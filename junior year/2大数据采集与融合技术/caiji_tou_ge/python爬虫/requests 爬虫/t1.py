import requests


def get_html(url, headers=None):
    '''
    ��������
    :param url:ͳһ��Դ��λ��,������ַ
    :param headers:����ͷ
    :return:html
    '''

    # ***************** Begin ******************** #

    # ��������ͷ
    headers = headers or {}

    # get������ҳ
    response = requests.get(url, headers=headers)

    # ��ȡ��ҳ��Ϣ�ı�
    html = response.text

    # ***************** End ******************** #

    return html
