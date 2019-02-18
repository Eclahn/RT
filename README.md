# What is RT

RT, or Ray Tracer, is a software using xml files to render geometrical objects in 3D scenes using ray tracing, as well as their interactions with light sources. Scenes can be visualized by multiple cameras that can be moved via an interface that allows modifications of the scene. It handles light refraction and multiple reflections, texture mapping on all objects, procedural texture generation through the Perlin noise algorithm, normal perturbation and more.

## Usage
This software runs only on MacOS.
The Makefile will install and compile all dependencies.
~~~~
Usage: make coffee
~~~~

## Controls
WASD keys allow you to move the current camera on a horizontal plane. 
The interface handles all other options, such as switching scenes or cameras, modifying or moving objects, applying or generating textures, save the modified scene as an xml file or taking a screenshot.
