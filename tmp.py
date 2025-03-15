# -*- coding: utf-8 -*-
"""
Created on Sun Sep 13 16:18:14 2020
@author: sunaga kazuki
"""
import requests
from bs4 import BeautifulSoup
import schedule
import time
text_ago = ''
text = ' '
def keyaki():
    # url = "http://toriizaka46.jp/"
    url = "http://vi-vo.link/module/n_woman.php"
    response = requests.get(url)
    response.encoding = response.apparent_encoding
    url = "https://notify-api.line.me/api/notify"
    access_token = 'ASqQ1KuCRjWnPJZ5cmgGmmkxLosek71swJncwMnApmV'
    headers = {'Authorization': 'Bearer ' + access_token}
    global text_ago, text
    bs = BeautifulSoup(response.text, 'html.parser')
    # print(bs)
    div_tag = bs.select('div.article.section-3')
    print(div_tag)
    # title_tag = div_tag[0].select('h3.article-title')
    # text = title_tag[0].text.strip()
    # if text_ago == text:
    #     pass
    # else:
    #     text_url = div_tag[0].select('a')
    #     text_url = text_url[0]['href']
    #     message = '{}:　{}'.format(text, text_url)
    #     payload = {'message': message}
    #     requests.post(url, headers=headers, params=payload)
    #     text_ago = text

schedule.every(5).minutes.do(keyaki)
if __name__ == "__main__":
    keyaki()
    while True:
        schedule.run_pending()
        time.sleep(1)