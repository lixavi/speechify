# speech_recognition/utils.py

from pydub import AudioSegment

def load_audio(audio_file_path):
    """
    Load audio file from disk and return AudioSegment object.
    """
    return AudioSegment.from_file(audio_file_path)

def convert_audio_format(audio, target_format='wav'):
    """
    Convert audio to the target format.
    """
    return audio.export(format=target_format)

def split_audio(audio, duration):
    """
    Split audio into segments of specified duration.
    """
    segments = []
    start = 0
    while start < len(audio):
        segments.append(audio[start:start+duration])
        start += duration
    return segments
