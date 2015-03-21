from SimpleCV import Image, Camera, Display
import time
cam = Camera()
img = cam.getImage()
img.show(type='browser')
#cam = Camera()
#cam.live()x
#cam.getImage().show()
#time.sleep(6)