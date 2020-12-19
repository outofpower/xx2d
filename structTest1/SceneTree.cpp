﻿#include "SceneTree.h"
#include "Viewport.h"
#include <thread>
#include "xx_chrono.h"

SceneTree::SceneTree() {
	root.Emplace(this);
	beginSeconds = lastSeconds = xx::NowEpochSeconds();
}

int SceneTree::MainLoop() {
	while (!root->children.empty()) {
		std::this_thread::sleep_for(std::chrono::milliseconds(16));	// simulate frame delay
		auto delta = (float)xx::NowEpochSeconds(lastSeconds);
		root->CallProcess(delta);
	}
	return 0;
}