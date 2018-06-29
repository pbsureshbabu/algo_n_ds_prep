// Following the book Open Source Computer Vision for beginners: Learn Opencv using c++ in fastest possible way.

1. Installed the community version of visual studio 2017 for x64 os
2. Downloaded the opencv3.3.0
3. downloaded cmake.

Created and ran a first test application.


// 2_sample_program.cpp
1. Using Mat data structure of OpenCV to allocate space for a matrix
2. Nice analogy given in the book, which is how a photographer takes the photo, uses a frame to put the photo in
   the frame and then delivers to the customer.
3. namedWindow() function of openCV is used to create the photo frame.
4. imread() function is used to read an image from a file and store it into the matrix.
5. imshow() function is used to show the image as the name says. For this function, you will have to give the 
   photo frame as well as the photo.
6. waitkey() as the name says, it waits for the key. Not sure on any other uses of it.
7. destoryWindow() - closes and reallocates the window.


// 3_sample_program.cpp
1. Using Mat data structure, but creating array of Mats for storing multiple images
2. namedWindow(), imread(), imshow and destroyWindow() are all used again but many times to each of the frames.