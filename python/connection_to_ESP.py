import cv2
import numpy as np
from urllib.request import urlopen

stream = urlopen('https://192.168.43.6:81/stream')
bytes = bytes()

while True:
    bytes += stream.read(1024)
    a = bytes.find(b'\xff\xd8')
    b = bytes.find(b'\xff\xd9')

    if a != -1 and b != -1:
        jpg = bytes[a:b + 2]
        bytes = bytes[b + 2:]
        if jpg:
            img = cv2.imdecode(np.fromstring(jpg, dtype = np.uint8), cv2.IMREAD_COLOR)
            cv2.imshow('ESP32 CAM', img)

        if cv2.waitKey(1) & 0xff == ord('q'):
            break

stream.release()
cv2.destroyAllWindows()

