# ./so_long

This project involved creating a 2D game using the MinilibX library in pure C.

![Screencastfrom2024-11-1820-16-19-ezgif com-video-to-gif-converter](https://github.com/user-attachments/assets/8636f32e-2d50-4cf3-ac9b-0bbe4539af85)

## Rules

- The map must be surrounded by walls, and the player moves using the WASD keys.  
- The player needs to collect all collectibles before reaching the exit.  
- Errors should trigger appropriate error messages.  

## How It Works

### Main Part

1. **Initialization**  
   A structure is initialized, setting all data to either `NULL` or `1`.  

2. **Input Validation**  
   - Check if the map file has a `.ber` extension.  
   - Verify the map has rectangular dimensions.  
   - Read the map using the `get_next_line` function and store it in a multidimensional array.  

3. **Map Validation**  
   - Ensure the map is fully surrounded by walls.  
   - Check for duplicate player starts, exits, or invalid characters.  

4. **Setup**  
   - Extract positions for the player and exit, and assign them to variables in the structure.  
   - Use a recursive Depth First Search (DFS) algorithm to verify that the map is solvable (player can reach the exit while collecting all items).  

5. **Rendering**  
   - Initialize a window and render the map based on the dimensions of the `.ber` file.  

6. **Gameplay**  
   - Hook functions for player movement and death events.  
   - On keypress, update the player’s position, re-render the map, and manage collectibles.  
   - Once all collectibles are gathered, the exit becomes accessible.  

7. **Error Handling**  
   - The `error()` function displays a specific message, cleans up all data, and safely exits.  

## ./so_long_bonus
#### Animations and Enemies

- Enemies and animations are added for the bonus part of the project.  
- Player animations trigger on movement or death.  
- Enemies patrol the map and can reset the player position upon contact.  
- A static variable loop controls FPS for smooth animations.

## What I Learned

- Working with structures to manage complex data.  
- Understanding and using a poorly documented library (MinilibX).  
- Creating animation loops with static variables to control FPS.  
- Designing a robust `error()` function to cleanly handle errors and free resources.  

## What I Enjoyed Most

Building the `error()` function was the highlight of this project. It ensures everything is safely cleaned up, preventing memory leaks or crashes.
