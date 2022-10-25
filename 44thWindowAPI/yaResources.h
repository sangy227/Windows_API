#pragma once
#include"Common.h"
#include "yaResource.h"

namespace ya {
	template <typename T>
	class Resources
	{

	public:
		typedef std::map<std::wstring, Resource*>::iterator ResourceIter;

		static T* Find(const std::wstring& key)
		{
			ResourceIter iter = mResources.find(key);

			//리소스가 이미 map안에 존재한다
			if (iter != mResources.end())
			{
				return dynamic_cast<T*>(iter->second);
			}
			return nullptr;
		
		}
		static T* Load(const std::wstring& key,const std::wstring& path)
		{
			T* resource = Find(key);
			//해당 키로 이미 로딩된게 있으면 리소스를 반환
			if (resource != nullptr)
				return resource;

			//리소스가 없다
			resource = new T();
			if (FAILED(resource->Load(path)))
			{
				MessageBox(nullptr, L"Image load Failed!!!", L"Error", MB_OK);
				return nullptr;
			}

			//???????? 10-25일 주석처리하니까 실행됨
			//resource->Setkey(key);
			//resource->Setpath(path);

			mResources.insert(std::make_pair(key, resource));

			return dynamic_cast<T*>(resource);
		}

	private:
		static std::map<std::wstring, Resource*> mResources;
	};
	template <typename T>
	std::map<std::wstring, Resource*> Resources<T>::mResources;
}

