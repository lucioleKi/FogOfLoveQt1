#include "Enums.h"
#include "Scene.h"
#include "ReadTxt.h"
#include "Shuffle.h"
#include "Occupation.h"
#include "Feature.h"
#include "ReadEffects.h"
#include <array>
#include <map>
#include <vector>
#include <string>
#include <iostream>

void split(const std::string& s, char delim, std::vector<std::string>& elems) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
};

std::map<std::string, std::string> importVocab(std::string fileName) {

	std::ifstream fs(fileName);
	std::string line;
	std::map<std::string, std::string> pairs;
	while (std::getline(fs, line)) {
		std::vector<std::string> info;
		split(line, '\t', info);
		pairs.insert({ info[0], info[1] });
	}
	return pairs;
};

std::vector<Feature> importFeatures(std::string fileName) {
	std::ifstream fs(fileName);
	std::string line;
	std::vector<Feature> features;
	while (std::getline(fs, line)) {
		std::vector<std::string> info;
		split(line, '\t', info);
		int temp = std::stoi(info[1]);
		PersonalityDim p = (PersonalityDim)temp;
		int number = std::stoi(info[2]);
		Feature o = Feature{ info[0], p, number};
		features.push_back(o);
	}
	features = Shuffle(features);
	return features;
};

std::vector<Occupation> importOccus(std::string fileName) {
	std::ifstream fs(fileName);
	std::string line;
	std::vector<Occupation> occus;
	while (std::getline(fs, line)) {
		std::vector<std::string> info;
		split(line, '\t', info);
		int temp = std::stoi(info[1]);
		PersonalityDim p = (PersonalityDim)temp;
		int number = std::stoi(info[2]);
		Occupation o = Occupation{ info[0], p, number };
		occus.push_back(o);
	}
	occus = Shuffle(occus);
	return occus;
};


std::vector<Trait> importTraits(std::string fileName) {
    std::ifstream fs(fileName);
    //std::string text = "Patient	Able to remain calm and not become annoyed while experiencing delays and problems.	0	5	3\n         Promiscuous	Having an unselective and casual approach to engaging in sexual relationships.	0	1	1\nJealous	Showing envious resentment of others' success. Being suspicious and possessive towards others.	0	4	3\nJust	Having a strong sense of what's right and what's wrong.	1	5	5\nTask-oriented	Concerned with one's activities and goals rather than other people.	1	2	-5\nPerfectionist	Refusing to accept anything less than perfection. Demands the highest standards possible.	1	0	5\nSpiritual	Embracing the humble belief that there are things greater than oneself.	0	5	3\nNarrow-minded	Judgmental and unreceptive to novel ideas or opinion.	1	1	-5\n            Greedy	Having an excessive and selfish desire for money or possessions.	0	5	-3\nIntense	Passionate, vocal and very serious about one's emotions and thoughts.	0	2	3\nIrresponsible	Taking actions without thought arcading about the impact of t those actions on others.	0	0	-3\nAdventurous	Willing to take risks and try new experiences, showing boldness in doing so.	1	1	5\nManipulative	Scheming and trying to influence the behavior of others for one's own advantage.	1	5	-5\nSensual	Appreciating arousing gratification of the senses; seeking to explore sensory pleasure.	1	1	5\nSubservient	Prepared to obey others without questions, considering own wishes as less important.	0	4	3\nDisorganized	Lacking coherence or systematic structure leading to various levels of disorder.	1	0	-5\nConservative	Favors traditional views and values. Often in opposition to change.	1	1	-5\nMacho	Aggressive pride in one's masculine qualities; being overly assertive and dominating.	1	4	-5\nHardened	Able to withstand hardship and deal with bad experiences without being emotionally affected.	0	3	-3\nAmbitious	Driven by a strong desire to reach hard-to-achieve goals.	1	0	5\nPretentious	Characterized by a showiness exaggerating one's dignity or importance.	0	5	-3\nImpulsive	Acting without forethought, following spontaneous desires or whims.	1	0	-5\nSecure	Free from anxiety and with a strong sense of oneself. Unafraid to engage with others.	0	3	-3\nFlirtatious	Inclined to playfully suggest sexual attraction without serious intent.	0	2	5\nKind	Having a benevolent nature and an attitude of friendliness.	1	4	5\nShy	Feeling uncomfortable and awkward in proximity of others, especially unfamiliar people.	0	2	-3\nHypocritical	Pretending to have higher standards and being more virtuous than is the case.	1	5	-5\nWorrywart	Inclined to excessive wording, especially about unimportant matters.	1	3	5\nWorkaholic	Compulsively working excessively hard, sacrificing other interests and responsibilities.	0	0	3\nCynical	Having an arrogant mistrust of others, believing all people are driven by pure self-interest.	1	4	-5\nInnocent	Being of pure intent and motive.	1	5	5\nRelaxed	Free from stress and tension. Feels on top of everything that happens.	1	3	-5\nInsecure	Lack of confidence, in particular self-confidence.	0	3	3\n            Cocky	Self-confident to a degree that is rude and arrogant.	0	4	-3\nDown-to-earth	Simple and straightforward. Prefers practical and proven approaches.	0	1	-3\nFun-loving	Cheerful, energetic and likes to have a good time.	1	2	5\nNurturing	Lovingly caring and protective of others to help them grow and develop.	1	4	5\nWithdrawn	Socially detached, preferring to be alone or observed at a distance.	1	2	-5\n";
	std::string line;
	std::vector<Trait> traits;
    while (std::getline(fs, line)) {

		std::vector<std::string> info;
		split(line, '\t', info);
		int goalType = std::stoi(info[2]);
		TraitGoalType g = (TraitGoalType)goalType;
		int temp = std::stoi(info[3]);
		PersonalityDim p = (PersonalityDim)temp;
		int number = std::stoi(info[4]);
		Trait t = Trait{info[0], info[1], g, p, number};
		traits.push_back(t);
    }
	traits = Shuffle(traits);
	return traits;
};

std::vector<Chapter> importChapters(std::string fileName, std::string effects) {
	std::ifstream fs(fileName);
	std::string line;
	std::vector<Chapter> chapters;
	while (std::getline(fs, line)) {
		std::vector<std::string> info;
		split(line, '\t', info);
		int i = std::stoi(info[0]);
		
		int l = std::stoi(info[2]);
		int temp = std::stoi(info[3]);
		Deck d1 = (Deck)temp;
		std::vector<Deck> d = { d1 };
		Chapter c = Chapter{ i, 'B', l, d};
		c.setTitle(info[4]);
		c.setLine(info[5]);
		std::vector<Choice> choices;
        for (int i = 6; i < info.size(); i++) {
			Choice choice = { info[i] };
			choices.push_back(choice);
		}
		c.setChoices(choices);
		chapters.push_back(c);
	}
	chapters = importChapterE(chapters, effects);
	std::map<std::string, std::string> vocab = importVocab("vocabulary.txt");
	chapters = Vocab(chapters, vocab);
	return chapters;
};

std::vector<Scene> importScenes(std::string fileName, std::string effects) {
	std::ifstream fs(fileName);
	std::string line;
	std::vector<Scene> scenes;
	while (std::getline(fs, line)) {
		std::vector<std::string> info;
		split(line, '\t', info);
		Scene newScene = generateScene(info);
		scenes.push_back(newScene);
	}
	scenes = importEffects(scenes, effects);
	std::map<std::string, std::string> vocab = importVocab("vocabulary.txt");
	scenes = Vocab(scenes, vocab);
    scenes = Shuffle(scenes);
	return scenes;
};

Scene generateScene(std::vector<std::string> info) {
	int i = std::stoi(info[0]);
	int temp = std::stoi(info[4]);
	Deck d = (Deck)temp;
	char w = info[5][0];
	Scene scene = Scene{ i, d, w };
	scene.setTitle(info[1]);
	if (info[2] == "N") {
		scene.setLine("");
	}
	else {
		scene.setLine(info[2]);
	}
	
	if (info[3] == "N") {
		scene.setExplain("");
	}
	else {
		scene.setExplain(info[3]);
	}
	if (w == 'B'||w == 'P'||w =='C'||w =='S'||w =='E'||w =='N'||w == 'R') {
		std::vector<Choice> choices;
        for (int i = 6; i < info.size(); i++) {
			Choice choice = { info[i] };
			choices.push_back(choice);
		}
		scene.setChoices(choices);
	}
	
	
	return scene;
};

std::vector<Scene> importEffects(std::vector<Scene> scenes, std::string fileName) {
	std::ifstream fs(fileName);
	std::string line;
	int index = 0;
	while (std::getline(fs, line)) {
		std::vector<std::string> info;
		split(line, '\t', info);
		int i = std::stoi(info[0]);
		scenes.at(i-1) = readEffects(scenes.at(i-1), info);
		index++;
	}
	return scenes;
};

std::vector<Chapter> importChapterE(std::vector<Chapter> chapters, std::string fileName) {
	std::ifstream fs(fileName);
	std::string line;
	int index = 0;
	while (std::getline(fs, line)) {
		std::vector<std::string> info;
		split(line, '\t', info);
		int i = std::stoi(info[0]);
		chapters.at(i - 1) = readEffectsC(chapters.at(i - 1), info);
		index++;
	}
	return chapters;
};
