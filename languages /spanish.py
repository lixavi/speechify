# languages/spanish.py

def common_spanish_words():
    """
    Return a list of common Spanish words.
    """
    return [
        "hola",
        "mundo",
        "python",
        "reconocimiento",
        "voz",
        "biblioteca",
        # Add more common Spanish words as needed
    ]

def spanish_pronunciation_rules(word):
    """
    Return pronunciation rules for a given Spanish word.
    """
    # Example: Define pronunciation rules for specific Spanish words
    pronunciation_rules = {
        "python": "ˈpajton",
        "reconocimiento": "re.ko.noθiˈmjento",
        # Add more pronunciation rules as needed
    }
    return pronunciation_rules.get(word, "Unknown")

def spanish_language_model():
    """
    Return the path to the Spanish language model file.
    """
    # Example: Return the path to the Spanish language model file
    return "spanish_language_model.lm"
