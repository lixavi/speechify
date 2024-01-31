# Speechify

Speechify is a Python-based library that allows for easy conversion of speech to text using Google's Speech Recognition API. It provides support for multiple languages and offers a flexible and customizable interface for speech recognition tasks.

## Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/your_username/Speechify.git
    ```

2. Navigate to the Speechify directory:

    ```bash
    cd Speechify
    ```

3. Install the required dependencies:

    ```bash
    pip install -r requirements.txt
    ```

## Usage

1. Import the `speechify` module in your Python script:

    ```python
    from speechify import transcribe
    ```

2. Call the `transcribe` function with the path to your audio file:

    ```python
    audio_file_path = "path/to/your/audio_file.wav"
    recognized_text = transcribe(audio_file_path, language='en-US', engine='google')
    print("Recognized text:", recognized_text)
    ```
3. Replace `'en-US'` with the desired language code (e.g., `'es-ES'` for Spanish) and `'google'` with the desired recognition engine (e.g., `'sphinx'` for CMU Sphinx).
