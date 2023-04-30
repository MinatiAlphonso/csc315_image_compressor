# Seam Carver
CSC 315: Data Structures and Algorithms<br/>
Fall 2019<br/>
Authors: Minati Alphonso & Dustin Richards<br/>
Skills: C++, OpenGL

## Overview
This is a content-aware image resizer. The program calculates the energy map of the image and chooses the lowest energy seam to remove using Dynamic Programming.

## How to run project locally
<ol>
  <li>In the command line, run the 'make' command.</li>
  <li>Next, run './main ./tower.png'. (tower.png is the name of the image, can be changed to your preference)</li>
</ol>

## Features
Once a PNG image is loaded according to the proper usage, it will be displayed to the user. At this point, the user may use these keys:<br/>
  <ul>
    <li> o - display RGB image (default)</li>
    <li> e - display energy image</li>
    <li> v - calculate and display a vertical seam</li>
    <li> h - calculate and display a horizontal seam</li>
    <li> - (minus) - remove the selected seam</li>
    <li> q - quit
  </ul>
  <br/>
To select a seam to remove, the user will press either h or v. The appropriate seam will then be calculated and displayed as a red line over the selected image type. The image type can be changed by pressing o or e. The energy image, selected with e, is the image used in calculated the seams and is itself calculated from the original RGB image. When - (minus) is pressed with a seam selected, that seam will be removed and the image will slide in to fill the space, leaving it one pixel shorter in the appropriate dimension.
