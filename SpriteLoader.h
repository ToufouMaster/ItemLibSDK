#pragma once

class SpriteLoader {
	private:
		std::map<std::wstring, cube::Sprite*> loaded_sprites;
	public:
		SpriteLoader() {}

		/*std::wstring GetModelFullName(std::wstring mod_id, std::wstring model_name) {
			return mod_id + L"/" + model_name;
		}*/

		cube::Sprite* LoadModel(std::wstring mod_id, cube::SpriteManager* sprite_manager, std::wstring model_name, std::string file_path) {
			if (IsSpriteLoaded(model_name)) {
				return nullptr;
			}

			std::string path = GetSpriteFilePath(mod_id, file_path);
			cube::Sprite* sprite = sprite_manager->CreateSprite();
			std::string model_id = std::to_string(sprite_manager->sprites.size());
			sprite_manager->ParseCubToSprite(sprite, path);
			sprite_manager->sprites.push_back(sprite);
			loaded_sprites.insert({ model_name, sprite });
			return sprite;
		}

		bool IsSpriteLoaded(std::wstring model_name) {
			auto search = loaded_sprites.find(model_name);
			if (search != loaded_sprites.end()) {
				return true;
			}
			return false;
		}

		// path: mods/mod_id/sprites/file_path.cub
		std::string GetSpriteFilePath(std::wstring mod_id, std::string file_path) {
			std::string s_mod_id(mod_id.begin(), mod_id.end());
			return std::string("Mods/") + s_mod_id + std::string("/sprites/") + file_path;
		}

		cube::Sprite* GetSprite(std::wstring model_name) {
			if (!IsSpriteLoaded(model_name)) return nullptr;
			auto search = loaded_sprites.find(model_name);
			return search->second;
		}
};