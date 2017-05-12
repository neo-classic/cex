#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
        // получаем любую подключённую камеру
        CvCapture* capture = cvCreateCameraCapture(CV_CAP_ANY); //cvCaptureFromCAM( 0 );
        assert( capture );

        //cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 640);//1280);
        //cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 480);//960);

        // узнаем ширину и высоту кадра
        double width = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
        double height = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
        printf("[i] %.0f x %.0f\n", width, height );

        IplImage* prev=0;
        IplImage* next=0;

        cvNamedWindow("capture", CV_WINDOW_AUTOSIZE);

        printf("[i] press Enter for capture image and Esc for quit!\n\n");

        int counter=0;
        char filename[512];

        while(1){
                // получаем кадр
                next = prev;

                prev = cvQueryFrame( capture );




                // показываем
                cvShowImage("capture", frame1);

                char c = cvWaitKey(33);

                if (c == 27) { // нажата ESC
                    break;
                }
                else if(c == 10) { // Enter
                    // сохраняем кадр в файл
                    sprintf(filename, "Image%d.jpg", counter);
                    printf("[i] capture... %s\n", filename);
                    cvSaveImage(filename, frame1, 0);
                    counter++;
                }
        }
        // освобождаем ресурсы
        cvReleaseCapture( &capture );
        cvDestroyWindow("capture");
        return 0;
}