#pragma once
#include <iostream>
#include <fmod.hpp>
#include <string>
#include <vector>
#include <algorithm>


class EunPlayer {

	struct fileSound {
		std::string filePath;
		FMOD::Sound * sound;
	};
public:
	EunPlayer() {

		FMOD::System_Create(&mSystem);
		mResult = mSystem->getVersion(&mVersion);
		mResult = mSystem->init(32, FMOD_INIT_NORMAL, nullptr);
	}
	void update() {
		mResult = mSystem->update();
	}
	bool FileEarse(std::string  _filePath) {
		auto i = fileFind(_filePath);
		if (i != mPSound.end())
			return false;
		mPSound.erase(i);
	}
	void FilePush(std::string  _filePath) {
		auto i = fileFind(_filePath);
		if (i != mPSound.end())
			return

			mPSound.push_back({ _filePath, nullptr });
		mPSound.push_back({ _filePath, nullptr });
		
		mResult = mSystem->createSound(mPSound.rbegin()->filePath.c_str(),
			FMOD_DEFAULT, 0, &mPSound.rbegin()->sound);
	}
	std::vector<fileSound>::iterator fileFind(std::string &_filePath) {
		return std::find_if(mPSound.begin(), mPSound.end(), [&](fileSound &_oth)->bool {
			return _oth.filePath == _filePath;
		});
	}
	void playSound(std::string str) {
		auto iter = fileFind(str);
		mResult = mSystem->playSound(iter->sound, 0, false, &mChannel);
	}

	bool isPlaying() {
		bool playing;
		mResult = mChannel->isPlaying(&playing);
		return playing;
	}
	void setPaused(bool setBool) {
		mChannel->setPaused(setBool);
	}
	~EunPlayer() {
		std::for_each(mPSound.begin(), mPSound.end(), [&](fileSound &obj) {
			mResult = obj.sound->release();
		});
		mResult = mSystem->close();
		mResult = mSystem->release();
	}



private:
	FMOD::Channel    *mChannel;
	FMOD::System *mSystem;
	std::vector<fileSound> mPSound;
	FMOD_RESULT mResult;
	unsigned int      mVersion;
};