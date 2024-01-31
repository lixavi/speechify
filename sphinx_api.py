
from pocketsphinx import LiveSpeech

def recognize_sphinx(audio_file, language):
    # Create a LiveSpeech object with language configuration
    speech = LiveSpeech(
        verbose=False,
        sampling_rate=16000,  # Adjust sampling rate if needed
        lm=False,
        hmm=None,
        dic=None,
        keyphrase=None,
        kws_threshold=1e-20,
        audio_device=None,
        audio_file=audio_file,
        buffer_size=2048,
        no_search=False,
        full_utt=False,
        hmm_dir=None,
        lm_dir=None,
        dic_dir=None,
        jsgf=None,
        kws=None,
        logfn=None
    )

    # Recognize speech from the audio file
    recognized_text = ""
    for phrase in speech:
        recognized_text += str(phrase) + " "
    
    return recognized_text.strip()
