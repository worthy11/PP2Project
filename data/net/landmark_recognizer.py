import numpy as np
import mediapipe as mp
import cv2

mp_hands = mp.solutions.hands
hand_recognizer = mp_hands.Hands()

def GetLandmarks(raw_data, width, height) -> list[float]:
    coords = []
    
    img = cv2.cvtColor(ConvertToNumpy(raw_data, width, height), cv2.COLOR_BGR2RGB)
    if img.shape[0] != 0:
        results = hand_recognizer.process(img)
        if results.multi_hand_landmarks: # HAND RECOGNIZED
            for hand_landmarks in results.multi_hand_landmarks:
                for landmark in hand_landmarks.landmark:
                    coords.append([landmark.x, landmark.y])
             
    return coords;

def ConvertToNumpy(raw_data, width, height) -> np.array:
    np_data = np.frombuffer(raw_data, dtype=np.uint8)
    if np_data.shape[0] == height*width*3:
        np_data = np.reshape(np_data, (height, width, 3))
        return np_data
    
    else: # BAD BUFFER SIZE
        return np.empty(0)