*This project has been created as part of the 42 curriculum by htate, yarikawa.*

---

# cub3D — My first RayCaster with miniLibX

## Description

cub3D is a 3D maze renderer written in C, inspired by **Wolfenstein 3D (1992)** — the world's first true First-Person Shooter.

The program takes a `.cub` scene file describing a 2D map and renders it as a first-person 3D view using the **ray-casting** technique, without any 3D graphics API.

### What is Ray Casting?

The world is actually a flat 2D grid. Ray casting is a trick that makes it *look* 3D by answering one question per screen column:

> "If I shoot a ray in this direction, how far away is the first wall it hits?"

The farther the wall, the shorter the vertical strip drawn on screen — giving the illusion of depth.

```
 TOP VIEW (2D reality)        SCREEN (3D illusion)
 ┌─────────────────┐          ┌──────────────────────┐
 │1 1 1 1 1 1 1 1 1│          │░░░░░░░░░░░░░░░░░░░░░░│  ← ceiling
 │1               1│          │██████████████████████│
 │1       P→      1│  rays→   │██  wall columns  ████│  ← walls
 │1               1│          │██████████████████████│
 │1 1 1 1 1 1 1 1 1│          │▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒│  ← floor
 └─────────────────┘          └──────────────────────┘
```

This technique was groundbreaking in 1992 because it ran in real time on hardware with no GPU.

### Key Concepts

**1. The Player**

The player has a 2D position `(x, y)` and a facing `angle`. The **Field of View (FOV)** — typically 60° — defines the cone of vision.

**2. One Ray Per Screen Column**

For each of the `WIDTH` (1280) columns on screen, one ray is cast. The first ray points `FOV/2` to the left of the player's angle, the last ray points `FOV/2` to the right:

```c
// draw.c
start = player->angle - player->fov / 2;
for each column i:
    cast ray at angle (start + i * fov / WIDTH)
```

**3. DDA — Digital Differential Analyzer**

Rather than checking every point along a ray (slow), DDA jumps efficiently from one grid cell to the next. It precomputes:

- `delta_dist_x` = how far the ray must travel to cross one vertical grid line
- `delta_dist_y` = how far to cross one horizontal grid line

Then at each step it advances to whichever grid line comes first, until it hits a wall (`'1'`).

```
         ↑ delta_dist_y
         │
─────────┼─────────┼──  ← grid lines
         │         │
─────────P──→──────┼──  ray goes right-down
         │delta_x  │
```

See the implementation at [srcs/render/raycasting.c](example/macos/srcs/render/raycasting.c).

**4. Perpendicular Wall Distance (Fish-Eye Correction)**

If you use the direct (Euclidean) distance to the wall, the screen curves like a fish-eye lens. The fix: use the **perpendicular distance** — the distance from the player to the wall projected onto the view plane.

```
perp_wall_dist = dist_x - delta_dist_x   (if vertical wall hit)
perp_wall_dist = dist_y - delta_dist_y   (if horizontal wall hit)
```

**5. Wall Strip Height**

The height of the wall strip for this column is simply:

```c
line_height = HEIGHT / perp_wall_dist;   // closer = taller
```

Half goes above screen center (ceiling side), half below (floor side).

**6. Texture Mapping**

Rather than a solid color, each wall face (N/S/E/W) has its own XPM texture.

- **Which texture?** → determined by which side the ray hit and the ray direction (`raycasting.c` sets `side`; `texture.c` maps it to N/S/E/W).
- **Which column of the texture (`tex_x`)?** → the fractional hit position on the wall face (`wall_x ∈ [0,1]` × `texture_width`).
- **Which row (`tex_y`)?** → stepping through the texture vertically in sync with screen pixels, scaled by `step = texture_height / line_height`.

**7. miniLibX Image Buffer**

Instead of calling `mlx_pixel_put()` per pixel (slow — flushes to screen each time), the implementation draws everything into an off-screen image buffer and flushes it once per frame with `mlx_put_image_to_window()`.

### Scene File Format (`.cub`)

```
NO ./textures/north.xpm     ← North wall texture path
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 40,113,39                 ← Floor color R,G,B
C 89,198,227                ← Ceiling color R,G,B

1111111111
1000000001
100N000001    ← N = player start, facing North
1000000001
1111111111
```

Map characters: `0` open space · `1` wall · `N/S/E/W` player start position and orientation.
The map must always be the **last element** in the file and must be **fully enclosed by walls**.

---

## Instructions

### Requirements

| Platform | Dependency |
|----------|-----------|
| macOS    | Xcode Command Line Tools |
| Linux    | `libx11-dev`, `libxext-dev` |

The `minilibx/` directory contains both versions — no separate download needed.

### Build

**macOS:**
```bash
cd example/macos
make
```

**Linux (校舎環境):**
```bash
cd example/linux
make
```

### Run

```bash
./cub3D <scene_file.cub>

# Example
./cub3D configfile/open_room.cub
```

### Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` `→` | Rotate view |
| `ESC` | Quit |
| Window `×` | Quit |

### Error Handling

Any invalid `.cub` file prints `Error\n` followed by a message and exits cleanly:

```bash
$ ./cub3D bad_map.cub
Error
the map must be surrounded by walls
```

---

## Resources

### References

- [Lode's Raycasting Tutorial](https://lodev.org/cgud/raycasting.html) — the definitive guide to the DDA algorithm and texture mapping used in this project
- [miniLibX Documentation (42)](https://harm-smits.github.io/42docs/libs/minilibx) — window, event, and image buffer API reference
- Wolfenstein 3D source code (1992, id Software) — historical reference for the original ray-casting engine

### AI Usage

Claude (Anthropic) was used in the following ways during this project:

- **Bug identification**: Static analysis of the existing codebase to identify issues such as missing `-Wall -Wextra -Werror` flags, unused variables causing compilation errors under strict flags, missing bounds checks on player movement, and asymmetric FOV calculation.
- **Platform separation**: Guidance on the differences between Linux (X11 keysyms, `mlx_destroy_display`) and macOS (Cocoa keycodes, OpenGL framework) miniLibX APIs, resulting in the `linux/` and `macos/` directory split.
- **Concept explanation**: Ray-casting algorithm, DDA traversal, fish-eye correction, and texture mapping were explained interactively to build understanding of the implementation.

All AI-generated content was reviewed, tested, and understood before inclusion. The student can explain every part of the implementation.
