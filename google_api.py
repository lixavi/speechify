# speech_recognition/google_api.py

import requests

def recognize_google(audio_file, language, api_key=None, speech_context=None):
    url = "https://speech.googleapis.com/v1/speech:recognize"
    
    headers = {
        "Content-Type": "application/json",
    }

    if api_key:
        params = {"key": api_key}
    else:
        params = {}

    request_data = {
        "config": {
            "encoding": "LINEAR16",
            "languageCode": language,
            "speechContexts": [{"phrases": speech_context}] if speech_context else [],
        },
        "audio": {
            "content": audio_file.read().decode("ISO-8859-1").encode("base64").decode(),
        },
    }

    response = requests.post(url, headers=headers, params=params, json=request_data)

    if response.status_code == 200:
        result = response.json()
        if "results" in result:
            return result["results"][0]["alternatives"][0]["transcript"]
        else:
            return "No speech recognized"
    else:
        return f"Error: {response.status_code} - {response.text}"
