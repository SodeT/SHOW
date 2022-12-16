from nltk.tag import pos_tag
from nltk.corpus import words
import nltk

def write_f(path, content):
    s = " ".join(content)
    f = open(path, 'w')
    
    f.write(s)
    f.close()


simplify = {
"CC" : "conjunction",
"CD" : "noun",
"DT" : "determiner",
"EX" : "noun",
"FW" : "foreign word",
"IN" : "preposition",
"JJ" : "adjective",
"JJR" : "adjective",
"JJS" : "adjective",
"LS" : "noun",
"MD" : "verb",
"NN" : "noun",
"NNS" : "noun",
"NNP" : "noun",
"NNPS" : "noun",
"PDT" : "determiner",
"POS" : "noun",
"PRP" : "pronoun",
"PRP$" : "pronoun",
"RB" : "adverb",
"RBR" : "adverb",
"RBS" : "adverb",
"RP" : "preposition",
"SYM" : "symbol",
"TO" : "preposition",
"UH" : "interjection",
"VB" : "verb",
"VBD" : "verb",
"VBG" : "verb",
"VBN" : "verb",
"VBP" : "verb",
"VBZ" : "verb",
"WDT" : "determiner",
"WP" : "pronoun",
"WP$" : "pronoun",
"WRB" : "adverb"}

conjunction = []
interjection = []
adjective = []
determiner = []
preposition = []
noun = []
verb = []
pronoun = []
adverb = []

word_list = words.words()
word_list = nltk.pos_tag(word_list)

simple_word_list = []
for word in word_list:
    simple_word_list.append((word[0], simplify[word[1]]))

for word in simple_word_list:
    if word[1] == "conjunction":
        conjunction.append(word[0])
    elif word[1] == "interjection":
        interjection.append(word[0])
    elif word[1] == "adjective":
        adjective.append(word[0])
    elif word[1] == "determiner":
        determiner.append(word[0])
    elif word[1] == "preposition":
        preposition.append(word[0])
    elif word[1] == "noun":
        noun.append(word[0])
    elif word[1] == "verb":
        verb.append(word[0])
    elif word[1] == "pronoun":
        pronoun.append(word[0])
    elif word[1] == "adverb":
        adverb.append(word[0])


write_f("conjunction.txt", conjunction)
write_f("interjection.txt", interjection)
write_f("adjective.txt", adjective)
write_f("determiner.txt", determiner)
write_f("preposition.txt", preposition)
write_f("noun.txt", noun)
write_f("verb.txt", verb)
write_f("pronoun.txt", pronoun)
write_f("adverb.txt", adverb)