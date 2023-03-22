from keras.models import load_model
import cv2
import numpy as np

cam = cv2.VideoCapture(0)
# Disable scientific notation for clarity
np.set_printoptions(suppress=True)

# Load the model
model = load_model("keras_Model.h5", compile=False)

# Load the labels
class_names = open("labels.txt", "r").readlines()

data = np.ndarray(shape=(1, 224, 224, 3), dtype=np.float32)

text = ""

while True:
    # Grab the webcamera's image.
    ret, image = cam.read()
    cols = image.shape[0]
    rows = image.shape[1]
    brightness = np.sum(image) / (255 * cols * rows)
    minimum_brightness = 0.66
    ratio = brightness / minimum_brightness
    if ratio < 1:
        image = cv2.convertScaleAbs(image, alpha = 1 / ratio, beta = 0)

    # Resize the raw image into (224-height,224-width) pixels
    image = cv2.resize(image, (224, 224))

    # turn the image into a numpy array
    image_array = np.asarray(image)

    # Normalize the image
    normalized_image_array = (image_array.astype(np.float32) / 127.0) - 1

    # Load the image into the array
    data[0] = normalized_image_array

    # Predicts the model
    prediction = model.predict(data)
    index = np.argmax(prediction)
    class_name = class_names[index]
    confidence_score = prediction[0][index]

    text = str(class_name) + '-'+str(confidence_score)
    print(str(class_name))
    image = cv2.resize(image, (500, 500))
    if confidence_score >= 0.7 and index == 0:
        cv2.putText(image, text, (10, 30), cv2.FONT_HERSHEY_COMPLEX_SMALL, 2, (0, 255, 0), 1)
    # Show the image in a window
    cv2.imshow("Webcam Image", image)

    # Listen to the keyboard for presses.
    keyboard_input = cv2.waitKey(1)

    # 27 is the ASCII for the esc key on your keyboard.
    if keyboard_input == 27:
        break

cam.release()
cv2.destroyAllWindows()






# # Read the input image
# image = cv2.imread('Anh-con-Sau.jpg')
#
# # Resize and normalize the image
# image = cv2.resize(image, (224, 224))
# image = (image / 127.5) - 1
#
# # Predict the class probabilities
# prediction = model.predict(np.array([image]))
#
# # Get the predicted class index and confidence score
# class_idx = np.argmax(prediction)
# class_name = class_names[class_idx].strip()
# confidence_score = prediction[0, class_idx]
#
# # Print the predicted class and confidence score
# print("Predicted class:", class_name)
# print("Confidence score:", confidence_score)
# # Extract the predicted class probabilities and bounding box coordinates
#
#
# # Draw the class label on the image
# font = cv2.FONT_HERSHEY_SIMPLEX
# text = "Class: {} ({:.2%})".format(class_name, confidence_score)
# cv2.putText(image, text, (10, 30), font, 1, (0, 255, 0), 2)
#
# # Display the image
# cv2.imshow("Prediction", image)
# cv2.waitKey(0)
# cv2.destroyAllWindows()






