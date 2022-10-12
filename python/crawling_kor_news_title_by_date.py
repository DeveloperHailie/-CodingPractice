import re
import requests
import pandas as pd
from bs4 import BeautifulSoup
from fake_useragent import UserAgent
from selenium import webdriver
import time
import csv

# text 정제하기
def clean_text(content):
    cleaned_text = re.sub('[a-zA-Z]', '', content)
    cleaned_text = re.sub('[\{\}\[\]\/?.,;:|\)*~`!^\-_+<>▶▽♡◀━@\#$%&\\\=\(\'\"ⓒ(\n)(\t)]', ' ', cleaned_text)
    cleaned_text = cleaned_text.replace("🇲\u200b🇮\u200b🇱\u200b🇱\u200b🇮\u200b🇪\u200b", "")
    cleaned_text = cleaned_text.replace("오류를 우회하기 위한 함수 추가 ", "")
    cleaned_text = cleaned_text.replace("동영상 뉴스 오류를 우회하기 위한 함수 추가 ", "")
    cleaned_text = cleaned_text.replace("무단전재 및 재배포 금지", "")
    return cleaned_text

def get_category(category):
    # 정치 100, 경제 101, 사회 102, 문화 103, 세계 104, 과학 105
    if category == 100 :
        return '정치'
    if category == 101 :
        return '경제'
    if category == 102 :
        return '사회'
    if category == 103 :
        return '문화'
    if category == 104 :
        return '세계'
    if category == 105 :
        return '과학'

def get_news(ranking, category, date) :
    f = open('C:\\Users\\hailie\\Desktop\\랩실\\UROP\\naver_news.csv', 'a', encoding='utf-8', newline='')
    wr = csv.writer(f)
    driver = webdriver.Chrome('./chromedriver')
    
    url = "https://news.naver.com/main/ranking/" + ranking + ".nhn?rankingType=popular_day&sectionId=" + str(category) + "&date=" + str(date)
    driver.get(url)

    news_title = []
    news_name = driver.find_elements_by_css_selector("strong.rankingnews_name") #언론사 이름
    ranking_title = driver.find_elements_by_css_selector("a.list_title") #기사 타이틀
    for i in range(len(ranking_title)) :
        title = clean_text(ranking_title[i].text)
        name= ''
        if title == '' :
            continue
        name = news_name[int(i/5)].text
        news_title.append([ranking,str(date),get_category(category),name,title]) 
        wr.writerow([ranking,str(date),get_category(category),name,title])
        
    driver.close()
    f.close()
    return news_title

def a_day_news(date) :
    # 정치 100, 경제 101, 사회 102, 문화 103, 세계 104, 과학 105
    # popularDay 많이본뉴스, popularMemo 댓글많은뉴스
    for i in range(100,106) :
        get_news("popularDay",i,date)
        get_news("popularMemo",i,date)
    


# 하루 한 카테고리당 60개 * 2종류 순위 => 하루 당 6*60*2 = 720
# 10일만 해도 7200개 데이터 얻을 수 있음
a_day_news(20200101)
a_day_news(20200102)
a_day_news(20200103)
a_day_news(20200104)
a_day_news(20200105)
a_day_news(20200106)
a_day_news(20200107)
a_day_news(20200108)
a_day_news(20200109)
a_day_news(20200110)



