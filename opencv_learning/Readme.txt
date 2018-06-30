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

// 4_sample_program.cpp
1. storing the image and for this imwrite() is used.
2. it takes, the file that needs to be created, filled and stored and the image itself as a matrix

// 5_sample_program.cpp
1. loading the image only w/ the independent gray scale (only one channel)

// 6_sample_program.cpp
1. creating three images with single channel and having three different pixel values on each.
2. one image is created w/ single channel having pixel value of 0 through out the image w/ 384x384 resolution.
3. other two images are created w/ single channel having pixel values of 100 and 255 respectively.

// 7_sample_program.cpp
1. creating four imags with three channels for each image.
2. initing the images w/ some data. for image1, just green channel is illuminated and the other two are set as 0, which is non-illumination.
3. The fourth image is initialized w/ mix of values, so as to give some difference than blue, green or red.

// 8_sample_program.cpp
1. a simple program to count the number of channels in the image
2. basically loading the image into the Mat object and using one of the member function to get the total channels.

// 9_sample_program.cpp
1. there is a function called split, which splits the channels and puts them into three different matrices.
2. and these three different matrices can be viewed separately.

// 10_sample_program.cpp
1. using cvtColor() function to convert the image's color spaces
2. here, an image is loaded to a Mat object and a convertion from RGB to gray scale is done.

