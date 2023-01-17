#pragma once
class TestSingleton final{

private:
	//�R���X�g���N�^��private�ɂ���
	TestSingleton();
	//�f�X�g���N�^��private�ɂ���
	~TestSingleton();
public:
	//�R�s�[�R���X�g���N�^�𖳌��ɂ���
	TestSingleton(const TestSingleton& obj) = delete;
	//������Z�q�𖳌��ɂ���
	TestSingleton& operator=(const TestSingleton& obj) = delete;

	static TestSingleton* GetInstance();//�ÓI�����o�[�֐�

	void Update();
};