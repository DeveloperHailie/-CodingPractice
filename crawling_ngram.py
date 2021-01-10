import nltk
import numpy as np
import random
import string
import re
import csv

def getNgram (article_text) :
    ngrams = {}
    words = 3
    
    words_tokens = nltk.word_tokenize(article_text)
    for i in range(len(words_tokens)-words):
        seq = ' '.join(words_tokens[i:i+words])
        print(seq)
        if  seq not in ngrams.keys():
            ngrams[seq] = []
        ngrams[seq].append(words_tokens[i+words])
        
    curr_sequence = ' '.join(words_tokens[0:words])
    output = curr_sequence
    for i in range(50):
        if curr_sequence not in ngrams.keys():
            break
        possible_words = ngrams[curr_sequence]
        next_word = possible_words[random.randrange(len(possible_words))]
        output += ' ' + next_word
        seq_words = nltk.word_tokenize(output)
        curr_sequence = ' '.join(seq_words[len(seq_words)-words:len(seq_words)])
        
    print(output)
    return output


f = open('C:\\Users\\hailie\\Desktop\\랩실\\UROP\\data\\news-kor.csv', 'r', encoding='utf-8')
rdr = csv.reader(f)
f = open('C:\\Users\\hailie\\Desktop\\랩실\\UROP\\data\\np-news-gram-kor.csv', 'w', encoding='utf-8', newline='')
wr = csv.writer(f)

for line in rdr:
    article_text = line[1] 
    article_text = re.sub(r'[^A-Za-z. ]', '', article_text)
    output = getNgram(article_text)
    wr.writerow([line[0],line[1],output])
f.close()


