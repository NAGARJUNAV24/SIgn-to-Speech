import serial
import time
from gtts import gTTS
import os
from playsound import playsound

# Function to convert text to speech and play the audio
def text_to_speech(text, lang='en', save_path='output.mp3'):
    # Ensure the directory exists before saving the file
    os.makedirs(os.path.dirname(save_path), exist_ok=True)

    # Check if the file already exists and delete it to replace
    try:
        if os.path.exists(save_path):
            os.remove(save_path)
            print(f"Existing file {save_path} removed.")
    except Exception as e:
        print(f"Error removing file {save_path}: {e}")
    
    # Convert the given text to speech using gTTS
    tts = gTTS(text=text, lang=lang)
    
    # Save the generated speech as an MP3 file at the specified path
    tts.save(save_path)
    print(f"Saved speech as: {save_path}")
    
    # Play the saved MP3 file and wait until it finishes
    play_audio_and_wait(save_path)

# Function to play audio using playsound and wait for it to finish
def play_audio_and_wait(file_path):
    try:
        print("Playing audio...")
        playsound(file_path)  # This will block until the audio finishes
        print("Audio playback finished.")
    except Exception as e:
        print(f"Error playing audio: {e}")

# Function to read serial data from Arduino
def read_serial_data(serial_port, baud_rate=9600):
    ser = serial.Serial(serial_port, baud_rate)
    time.sleep(2)  # Wait for connection to stabilize

    while True:
        if ser.in_waiting > 0:
            text = ser.readline().decode('utf-8').strip()
            print(f"Received text: {text}")
            yield text
        time.sleep(0.1)

# Main execution
if __name__ == "__main__":
    serial_port = "COM3"  # Change this to your actual COM port
    save_directory = "D:/ttsaudio/output.mp3"  # Adjust if needed

    for text in read_serial_data(serial_port):
        text_to_speech(text, save_path=save_directory)
        print("Waiting 12 seconds before reading next input...")
