# miniRT
42 Curriculum (Level 4) - Ray tracing project
  
## Principles  

A raytracer simulates the way light interacts with an environment and the way it is perceived by a receiver (eye / camera / ...)  
Úsually this is done creating a section of a visual cone with a rectangular viewport (which would be the screen). In this case the subject of the project requires the field of view to reach 180 degrees: in this case the afore mentioned approach would couse the "screen" to virtually cut the receiver, which would not render anything since the receiver is geometrically a point in R3.  
Due to these considerations a spherical viewport was used: this cuts the rays at 1 unit of distance from the receiver, making the use of trigonometric functions more immediate.  
  
![camera_scheme](https://user-images.githubusercontent.com/61493084/177810010-66f22ddf-940c-40b8-93ea-f3ca86170251.png)
  
The result is a spherical projection on a plane (as a world map may be)  
  
## How to use the ray tracer  
  
1. `git clone <repository>`  
2. `cd miniRT && make`  
3. `./miniRT example.rt`  
  
A set of scenes (.rt) is stored in the directory `scenes`  
For example, running the command `./miniRT scenes/c1_temple.rt` the following image will be generated  
![Screenshot from 2022-07-07 16-57-56](https://user-images.githubusercontent.com/61493084/177805518-fda58850-0ca1-4770-b13d-3d5df7e4fc4b.png)
  
When the render is complete, it is possible to alter the components of the image following some steps:  
1. Select an object: this may be a geometry in the scene, the light, or the camera  
2. Select the object index: this is useful only if there is more than one object per type selected in the scene (if there is only one sphere, the only one that can be selected is the n. 0)  
3. Select an action: this could be rotation, translation or redimension  
4. Select a dimension: this is going to let you choose an axis in case you selected rotation or translation, or it is going to let you choose between ray and (if available) height in case you selected redimension  
5. Select a magnitude: this is going to let you choose the new dimension or how much the object should move (translate or rotate) according to what you selected  
6. Once ENTER is pressed the scene is going to render once more to adapt to the changes  

Thank you for browsing this project
