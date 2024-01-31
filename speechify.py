# speechify.py

from speech_recognition import google_api
from languages import english, spanish

def recognize_speech(audio_file, language='en-US', engine='google'):
    if engine == 'google':
        if language.startswith('en'):
            return google_api.recognize_google(audio_file, language)
        elif language.startswith('es'):
            return google_api.recognize_google(audio_file, language)
        else:
            raise ValueError("Language not supported by Google Speech Recognition")
    else:
        raise ValueError("Speech recognition engine not supported")

def transcribe(audio_file_path, language='en-US', engine='google'):
    try:
        # Load audio file
        with open(audio_file_path, 'rb') as audio_file:
            # Perform speech recognition
            text = recognize_speech(audio_file, language, engine)
            return text
    except FileNotFoundError:
        return "Error: Audio file not found"
    except ValueError as ve:
        return str(ve)
    except Exception as e:
        return f"Error occurred: {str(e)}"

if __name__ == "__main__":
    audio_file_path = "sample_audio.wav"
    recognized_text = transcribe(audio_file_path)
    print("Recognized text:", recognized_text)
