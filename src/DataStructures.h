#pragma once

struct Registers
{
	struct
	{
		union
		{
			struct
			{
				/// <summary>
				/// 8bit F register
				/// </summary>
				unsigned char f;

				/// <summary>
				/// 8bit A register
				/// </summary>
				unsigned char a;
			};
			/// <summary>
			/// 16bit AF register
			/// </summary>
			unsigned short af=0;
		};
	};
	struct
	{
		union
		{
			struct
			{
				/// <summary>
				/// 8bit C register
				/// </summary>
				unsigned char c;

				/// <summary>
				/// 8bit B register
				/// </summary>
				unsigned char b;
			};

			/// <summary>
			/// 16bit BC register
			/// </summary>
			unsigned short bc=0;
		};
	};
	struct
	{
		union
		{
			struct
			{
				/// <summary>
				/// 8bit E register
				/// </summary>
				unsigned char e;

				/// <summary>
				/// 8bit D register
				/// </summary>
				unsigned char d;
			};
			/// <summary>
			/// 16bit DE register
			/// </summary>
			unsigned short de=0;
		};
	};
	struct
	{
		union
		{
			struct
			{
				/// <summary>
				/// 8bit L register
				/// </summary>
				unsigned char l;

				/// <summary>
				/// 8bit H register
				/// </summary>
				unsigned char h;
			};
			/// <summary>
			/// 16bit HL register
			/// </summary>
			unsigned short hl=0;
		};
	};
	/// <summary>
	/// 16bit Stack Pointer
	/// </summary>
	unsigned short sp=0;
	
	/// <summary>
	/// 16bit Program Counter
	/// </summary>
	unsigned short pc=0;
};