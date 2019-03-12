import numpy as np
import cv2
import time

video_dir = r"your directory here"

# Define the duration (in seconds) of the video capture here
capture_duration = 5.5

cap = cv2.VideoCapture(1) #Id of webcam

# Define the codec and create VideoWriter object
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter(video_dir,fourcc, 25.0, (640,480)) #25 is the fps
start_time = time.time()
while( int(time.time() - start_time) < capture_duration ):
    ret, frame = cap.read()
    if ret==True:
        frame = cv2.flip(frame,0)

        # write the flipped frame
        out.write(frame)

        cv2.imshow('frame',frame)
        #if cv2.waitKey(1) & 0xFF == ord('q'):
        #    break
    else:
        break

# Release everything if job is finished
cap.release()
out.release()
cv2.destroyAllWindows()