import numpy as np
import pandas as pd
from sklearn.utils.multiclass import type_of_target
import tree_plottter
import pruning
import matplotlib as plt

plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False


class Node(object):  # �ڵ���
    def __init__(self):  # ��ʼ��
        self.feature_name = None  # ������
        self.feature_index = None  # ��������
        self.subtree = {}
        self.impurity = None  # ������
        self.is_continuous = False  # �Ƿ�������ֵ
        self.split_value = None  # ����ֵ
        self.is_leaf = False  # �Ƿ���Ҷ�ڵ�
        self.leaf_class = None  # Ҷ�ڵ����
        self.leaf_num = None  # Ҷ�ڵ����
        self.high = -1  # ���ĸ߶�


class DecisionTree(object):  # ��������
    """
    û�����ȱʧֵ�����������
    """

    def __init__(self, criterion='gini', pruning=None):  # ��ʼ��
        """

        :param criterion: ���ַ���ѡ��'gini', 'infogain', 'gainratio', ����ѡ��
        :param pruning:   �Ƿ��֦ 'pre_pruning' 'post_pruning'
        """
        self.columns = None
        assert criterion in ('gini', 'infogain', 'gainratio')  # ����
        assert pruning in (None, 'pre_pruning', 'post_pruning')  # ����
        self.criterion = criterion  # ���ַ���
        self.pruning = pruning  # ��֦����

    def fit(self, X_train, y_train, X_val=None, y_val=None):  # ���
        """
        ���ɾ�����
        -------
        :param X:  ֻ֧��DataFrame�������ݣ���ΪDataFrame������������ʡȥһ�������Ĳ�������֧��np.array��������������
        :param y:
        :return:
        """

        if self.pruning is not None and (X_val is None or y_val is None):  # �����֦��Ϊ�գ�������֤��Ϊ��
            raise Exception('you must input X_val and y_val if you are going to pruning')  # �׳��쳣

        X_train.reset_index(inplace=True, drop=True)  # ��������
        y_train.reset_index(inplace=True, drop=True)  # ��������

        if X_val is not None:  # �����֤����Ϊ��
            X_val.reset_index(inplace=True, drop=True)  # ��������
            y_val.reset_index(inplace=True, drop=True)  # ��������

        self.columns = list(X_train.columns)  # ����ԭ���ݵ�����
        self.tree_ = self.generate_tree(X_train, y_train)  # ���ɾ�����

        if self.pruning == 'pre_pruning':  # �����Ԥ��֦
            pruning.pre_pruning(X_train, y_train, X_val, y_val, self.tree_)  #
        elif self.pruning == 'post_pruning':  # ����Ǻ��֦
            pruning.post_pruning(X_train, y_train, X_val, y_val, self.tree_)

        return self

    def generate_tree(self, X, y):  # ���ɾ�����
        my_tree = Node()  # �ڵ���
        my_tree.leaf_num = 0  # Ҷ�ڵ����
        if y.nunique() == 1:  # ����ͬһ���
            my_tree.is_leaf = True  # ��Ҷ�ڵ�
            my_tree.leaf_class = y.values[0]  # Ҷ�ڵ����
            my_tree.high = 0  # �߶�
            my_tree.leaf_num += 1  # Ҷ�ڵ����
            return my_tree  # ���ؽڵ���

        if X.empty:  # ���������ˣ�����Ϊ�գ�����������������
            my_tree.is_leaf = True  # ��Ҷ�ڵ�
            my_tree.leaf_class = pd.value_counts(y).index[0]  # Ҷ�ڵ����
            my_tree.high = 0  # �߶�
            my_tree.leaf_num += 1  # Ҷ�ڵ����
            return my_tree  # ���ؽڵ���

        best_feature_name, best_impurity = self.choose_best_feature_to_split(X, y)  # ѡ���������

        my_tree.feature_name = best_feature_name  # ������
        my_tree.impurity = best_impurity[0]  # ������
        my_tree.feature_index = self.columns.index(best_feature_name)  # ��������

        feature_values = X.loc[:, best_feature_name]  # ����ֵ

        if len(best_impurity) == 1:  # ��ɢֵ
            my_tree.is_continuous = False

            unique_vals = pd.unique(feature_values)  # ����ֵȥ��
            sub_X = X.drop(best_feature_name, axis=1)

            max_high = -1
            for value in unique_vals:  # ����ÿһ������ֵ
                my_tree.subtree[value] = self.generate_tree(sub_X[feature_values == value],
                                                            y[feature_values == value])  # ��������
                if my_tree.subtree[value].high > max_high:  # ��¼��������ߵĸ߶�
                    max_high = my_tree.subtree[value].high  # ��߸߶�
                my_tree.leaf_num += my_tree.subtree[value].leaf_num  # Ҷ�ڵ����

            my_tree.high = max_high + 1  # �߶�

        elif len(best_impurity) == 2:  # ����ֵ
            my_tree.is_continuous = True  # ������ֵ
            my_tree.split_value = best_impurity[1]
            up_part = '>= {:.3f}'.format(my_tree.split_value)
            down_part = '< {:.3f}'.format(my_tree.split_value)

            my_tree.subtree[up_part] = self.generate_tree(X[feature_values >= my_tree.split_value],
                                                          y[feature_values >= my_tree.split_value])
            my_tree.subtree[down_part] = self.generate_tree(X[feature_values < my_tree.split_value],
                                                            y[feature_values < my_tree.split_value])

            my_tree.leaf_num += (my_tree.subtree[up_part].leaf_num + my_tree.subtree[down_part].leaf_num)

            my_tree.high = max(my_tree.subtree[up_part].high, my_tree.subtree[down_part].high) + 1

        return my_tree

    def predict(self, X):  # Ԥ��
        """
        ͬ��ֻ֧�� pd.DataFrame��������
        :param X:  pd.DataFrame ����
        :return:
        """
        if not hasattr(self, "tree_"):  # ���û������
            raise Exception('you have to fit first before predict.')  # �׳��쳣
        if X.ndim == 1:  # ���ά��Ϊ1
            return self.predict_single(X)  # Ԥ�ⵥһ����
        else:
            return X.apply(self.predict_single, axis=1)  # Ԥ��������

    def predict_single(self, x, subtree=None):  # Ԥ�ⵥһ����
        """
        Ԥ�ⵥһ������
        :param x:
        :param subtree: �������������µݽ���������
        :return:
        """
        if subtree is None:  # �������Ϊ��
            subtree = self.tree_  # ����Ϊ������

        if subtree.is_leaf:  # �����Ҷ�ڵ�
            return subtree.leaf_class  # ����Ҷ�ڵ����

        if subtree.is_continuous:  # ��������ֵ����Ҫ�ж���
            if x[subtree.feature_index] >= subtree.split_value:
                return self.predict_single(x, subtree.subtree['>= {:.3f}'.format(subtree.split_value)])
            else:
                return self.predict_single(x, subtree.subtree['< {:.3f}'.format(subtree.split_value)])
        else:
            return self.predict_single(x, subtree.subtree[x[subtree.feature_index]])

    def choose_best_feature_to_split(self, X, y):  # ѡ���������
        assert self.criterion in ('gini', 'infogain', 'gainratio')  # ����

        if self.criterion == 'gini':  # �����gini
            return self.choose_best_feature_gini(X, y)

    def choose_best_feature_gini(self, X, y):  # ѡ���������gini
        features = X.columns  # ������
        best_feature_name = None  # ���������
        best_gini = [float('inf')]  # ���gini
        for feature_name in features:  # ����ÿһ������#
            is_continuous = type_of_target(X[feature_name]) == 'continuous'  # �ж��Ƿ�Ϊ����ֵ
            gini_idex = self.gini_index(X[feature_name], y, is_continuous)  # ����giniָ��
            if gini_idex[0] < best_gini[0]:  # ���giniָ��С�����gini
                best_feature_name = feature_name  # ���������Ϊ��ǰ������
                best_gini = gini_idex  # ���giniΪ��ǰgini

        return best_feature_name, best_gini

    def gini_index(self, feature, y, is_continuous=False):  # �������ָ��
        """
        �������ָ���� ��������ֵ��ѡ�����ϵͳ��С�ĵ㣬��Ϊ�ָ��
        -------
        :param feature:
        :param y:
        :return:
        """
        m = y.shape[0]
        unique_value = pd.unique(feature)  # ����ֵ
        if is_continuous:
            unique_value.sort()  # ����, ���ڽ����ָ��
            # ������ʵҲ����ֱ����featureֵ��Ϊ�ָ�㣬����������ֿռ��� ���Ի��ǰ�������4.7ʽ�����ָ�㡣�ô��ǲ�����ֿռ�
            split_point_set = [(unique_value[i] + unique_value[i + 1]) / 2 for i in range(len(unique_value) - 1)]

            min_gini = float('inf')
            min_gini_point = None
            for split_point_ in split_point_set:  # �������еķָ�㣬Ѱ�һ���ָ����С�ķָ��
                Dv1 = y[feature <= split_point_]
                Dv2 = y[feature > split_point_]
                gini_index = Dv1.shape[0] / m * self.gini(Dv1) + Dv2.shape[0] / m * self.gini(Dv2)

                if gini_index < min_gini:
                    min_gini = gini_index
                    min_gini_point = split_point_
            return [min_gini, min_gini_point]
        else:
            gini_index = 0
            for value in unique_value:
                Dv = y[feature == value]
                m_dv = Dv.shape[0]
                gini = self.gini(Dv)  # ԭ��4.5ʽ
                gini_index += m_dv / m * gini  # 4.6ʽ

            return [gini_index]

    def gini(self, y):
        p = pd.value_counts(y) / y.shape[0]
        gini = 1 - np.sum(p ** 2)
        return gini


if __name__ == '__main__':
    data_path2 = r'D:\JueCeShu\watermelon.txt'
    data = pd.read_table(data_path2, encoding='gbk', delimiter=',', index_col=0)

    train = [1, 2, 3, 6, 7, 10, 14, 15, 16, 17]
    train = [i - 1 for i in train]
    X = data.iloc[train, :6]
    y = data.iloc[train, 6]

    test = [4, 5, 8, 9, 11, 12, 13]
    test = [i - 1 for i in test]

    X_val = data.iloc[test, :6]
    y_val = data.iloc[test, 6]

    tree = DecisionTree('gini', 'pre_pruning')
    tree.fit(X, y, X_val, y_val)

    print(np.mean(tree.predict(X_val) == y_val))
    tree_plottter.create_plot(tree.tree_)