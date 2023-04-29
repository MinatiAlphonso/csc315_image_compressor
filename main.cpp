/**
 * @file main.cpp
 *
 * @mainpage Seam Carver
 *
 * @section course_section Course Information
 *
 * @author Dustin Richards
 * @author Minati Alphonso
 *
 * @date Nov. 25, 2019
 *
 * @par Course:
 *      CSC315 - Fall 2019
 *
 * @brief A content-aware image resizer.
 * @details Once a PNG image is loaded according to the proper usage, it will
 * be displayed to the user. At this point, the user may use these keys:\n
 *    - o - display RGB image (default)\n
 *    - e - display energy image\n
 *    - v - calculate and display a vertical seam\n
 *    - h - calculate and display a horizontal seam\n
 *    - \- (minus) - remove the selected seam\n
 *    - q - quit
 *
 * To select a seam to remove, the user will press either h or v. The
 * appropriate seam will then be calculated and displayed as a red line over
 * the selected image type. The image type can be changed by pressing o or e.
 * The energy image, selected with e, is the image used in calculated the seams
 * and is itself calculated from the original RGB image.
 * When - (minus) is pressed with a seam selected, that seam will be removed
 * and the image will slide in to fill the space, leaving it one pixel shorter
 * in the appropriate dimension.
 *
 * **Usage:** ./main ./img.png
 */

#include <iostream>
#include "util.h"

using namespace std;

/***************************************************************************//**
 * @brief main function
 *
 * @param[in] argc - Integer describing the number of command line arguments
 * @param[in] argv - Array of character strings that stores command line args
 *
 * @returns 0 iff the program exits normally
 ******************************************************************************/
int main(int argc, char** argv) 
{
   char *filename = nullptr;

   // Expect the user to give a path to a file to open
   if (argc != 2)
   {
      cout << "Usage: " << argv[0] << " image.png" << endl;
      return 1;
   }
   filename = argv[1];

   glutInit(&argc, argv);
   initOpenGL(filename);
   glutMainLoop();

   return 0;
}
