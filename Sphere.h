﻿#ifndef SPHERE_HEADER_
#define SPHERE_HEADER_

#include <d3d12.h>
#include <wrl/client.h>

using namespace Microsoft::WRL;

class Sphere {
public:
	typedef unsigned char byte;
	typedef unsigned short uint16;
	static constexpr int VERT_NUM = 32; // 一つの弧を作る頂点の数
	static constexpr int ARC_NUM = 32;  // 球を作る弧の数

public:
	Sphere();
	~Sphere() {}
	HRESULT Initialize(ID3D12Device* device);
	HRESULT Draw(ID3D12GraphicsCommandList* command_list);

private:
	ComPtr<ID3D12Resource> vertex_buffer_;
	ComPtr<ID3D12Resource> index_buffer_;
	ComPtr<ID3D12Resource> constant_buffer_;
	ComPtr<ID3D12Resource> texture_;
	ComPtr<ID3D12DescriptorHeap> dh_texture_;
};

#endif