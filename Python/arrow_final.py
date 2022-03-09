import cv2
import numpy as np
import serial
import time
hehe = 0
def detect():
    img = cv2.imread("arrow.png")

    gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

    edges = cv2.Canny(gray,50,150,apertureSize = 3)

    lines = cv2.HoughLines(edges,1,np.pi/180,20)

    left = [0, 0]
    right = [0, 0]
    up = [0, 0]
    down = [0, 0]

    for object in lines:
        theta = object[0][1]
        rho = object[0][0]
        
        if ((np.round(theta, 2)) >= 1.0 and (np.round(theta, 2)) <= 1.1) or ((np.round(theta,2)) >= 2.0 and (np.round(theta,2)) <= 2.1):
            if (rho >= 20 and rho <=  30):
                left[0] += 1
            elif (rho >= 60 and rho <= 65):
                left[1] +=1
            elif (rho >= -73 and rho <= -57):
                right[0] +=1
            elif (rho >=148 and rho <= 176):
                right[1] +=1
        
        elif ((np.round(theta, 2)) >= 0.4 and (np.round(theta,2)) <= 0.6) or ((np.round(theta, 2)) >= 2.6 and (np.round(theta,2))<= 2.7):
            if (rho >= -63 and rho <= -15):
                up[0] += 1
            elif (rho >= 67 and rho <= 74):
                down[1] += 1
                up[1] += 1
            elif (rho >= 160 and rho <= 171):
                down[0] += 1

    if left[0] >= 1 and left[1] >= 1:
        print("right")
        return 1
    elif right[0] >= 1 and right[1] >= 1:
        print("left")
        return 2
    else:
        return 0

    if cv2.waitKey(10) & 0xFF == ord('q'):
        cv2.destroyAllWindows()


def preprocess(img):
    img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    img_blur = cv2.GaussianBlur(img_gray, (5, 5), 1)
    img_canny = cv2.Canny(img_blur, 50, 50)
    kernel = np.ones((3, 3))
    img_dilate = cv2.dilate(img_canny, kernel, iterations=2)
    img_erode = cv2.erode(img_dilate, kernel, iterations=1)
    return img_erode

def find_tip(points, convex_hull):
    length = len(points)
    indices = np.setdiff1d(range(length), convex_hull)

    for i in range(2):
        j = indices[i] + 2
        if j > length - 1:
            j = length - j
        if np.all(points[j] == points[indices[i - 1] - 2]):
            return tuple(points[j])
def serial_a(a):
    ser = serial.Serial('COM3', 9600, timeout=1)
    time.sleep(2)

    if a == 2:
        user_input = 'H'
        byte_command = user_input.encode()
        ser.writelines(byte_command)   # send a byte
        time.sleep(0.5)
        user_input = 'L'
        byte_command = user_input.encode()
        ser.writelines(byte_command)
        time.sleep(0.5)
    elif a==1:
        user_input = 'H'
        byte_command = user_input.encode()
        ser.writelines(byte_command)   # send a byte
        time.sleep(0.5)
        user_input = 'L'
        byte_command = user_input.encode()
        ser.writelines(byte_command)
        time.sleep(0.5)
        user_input = 'H'
        byte_command = user_input.encode()
        ser.writelines(byte_command)
        user_input = 'L'
        byte_command = user_input.encode()
        ser.writelines(byte_command)
        time.sleep(0.5)
    else:
        user_input = 'L'
        byte_command = user_input.encode()
        ser.writelines(byte_command)
        time.sleep(0.5)
    ser.close()

l = list()
cap = cv2.VideoCapture(0)
while cap.isOpened():

    ret, img = cap.read()

    contours, hierarchy = cv2.findContours(preprocess(img), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)

    for cnt in contours:
        peri = cv2.arcLength(cnt, True)
        approx = cv2.approxPolyDP(cnt, 0.025 * peri, True)
        hull = cv2.convexHull(approx, returnPoints=False)
        sides = len(hull)

        if 6 > sides > 3 and sides + 2 == len(approx):
            arrow_tip = find_tip(approx[:,0,:], hull.squeeze())
            if arrow_tip:
                cv2.drawContours(img, [cnt], -1, (0, 255, 0), 3)
                cv2.circle(img, arrow_tip, 3, (0, 0, 255), cv2.FILLED)

    cv2.imwrite("arrow.png", img)
    cv2.imwrite(f"Temp/storage/arrow{hehe}.png", img)
    hehe+=1
    arr = detect()
    if len(l)==0:
        l.append(arr)
        print("---BLINK---")
        #serial_a(arr)
    elif arr!=l[0] and len(l)<6:
        l.append(arr)
    else:
        l = list()
    cv2.imshow("Image", img)
    if cv2.waitKey(10) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()

