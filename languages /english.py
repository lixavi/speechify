def common_english_words():
    """
    Return a list of common English words.
    """
    return [
        "hello",
        "world",
        "python",
        "speech",
        "recognition",
        "library",
        # Add more common English words as needed
    ]

def english_pronunciation_rules(word):
    """
    Return pronunciation rules for a given English word.
    """
    # Example: Define pronunciation rules for specific English words
    pronunciation_rules = {
        "python": "ˈpaɪθən",
        "recognition": "ˌrekəɡˈnɪʃən",
        # Add more pronunciation rules as needed
    }
    return pronunciation_rules.get(word, "Unknown")

def english_language_model():
    """
    Return the path to the English language model file.
    """
    # Example: Return the path to the English language model file
    return "english_language_model.lm"
