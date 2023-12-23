import requests


def get_html(url, headers=None):
    '''
    ��������
    :param url:ͳһ��Դ��λ��,������ַ
    :param headers:����ͷ
    :return html ��ҳ��Դ��
    :return sess �����ĻỰ
    '''

    # ***************** Begin ******************** #

    # ��������ͷ
    headers = headers or {}

    # ����Session, ��ʹ��Session��get������ҳ
    sess = requests.Session()
    response = sess.get(url, headers=headers)

    # ��ȡ��ҳ��Ϣ�ı�
    html = response.text

    # ****************** End ********************* #

    return html, sess
