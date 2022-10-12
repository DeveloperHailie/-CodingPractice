import csv
from selenium import webdriver
import time
f = open('C:\\Users\\hailie\\Desktop\\랩실\\UROP\\data\\all-data.csv', 'r', encoding='utf-8')
rdr = csv.reader(f)
lines = []
for line in rdr:
    lines.append(line)
    # print(line)
f.close()

f = open('C:\\Users\\hailie\\Desktop\\랩실\\UROP\\data\\news-kor.csv', 'w', encoding='utf-8', newline='')
wr = csv.writer(f)

driver = webdriver.Chrome('./chromedriver')

# 파파고 접속
driver.get('https://papago.naver.com/')
time.sleep(1)
results = []
for line in lines :
    # 번역할 문장 입력
    driver.find_element_by_css_selector('#sourceEditArea textarea').clear()
    driver.find_element_by_css_selector('#sourceEditArea textarea').send_keys(line[1])
    # 번역 버튼 클릭
    driver.find_element_by_css_selector('#btnTranslate').click()    
    time.sleep(1)
    result = driver.find_element_by_css_selector('#targetEditArea span').text
    results.append([line[0],result])
    wr.writerow([line[0],result])
    print(result)
     
f.close()