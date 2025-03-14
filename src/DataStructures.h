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
				char f;

				/// <summary>
				/// 8bit A register
				/// </summary>
				char a;
			};
			/// <summary>
			/// 16bit AF register
			/// </summary>
			short af;
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
				char c;

				/// <summary>
				/// 8bit B register
				/// </summary>
				char b;
			};

			/// <summary>
			/// 16bit BC register
			/// </summary>
			short bc;
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
				char e;

				/// <summary>
				/// 8bit D register
				/// </summary>
				char d;
			};
			/// <summary>
			/// 16bit DE register
			/// </summary>
			short de;
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
				char l;

				/// <summary>
				/// 8bit H register
				/// </summary>
				char h;
			};
			/// <summary>
			/// 16bit HL register
			/// </summary>
			short hl;
		};
	};
	/// <summary>
	/// 16bit Stack Pointer
	/// </summary>
	short sp;
	
	/// <summary>
	/// 16bit Program Counter
	/// </summary>
	short pc;
};