// CkPdf.h: interface for the CkPdf class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat 9.5.0.83

#ifndef _CkPdf_H
#define _CkPdf_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkMultiByteBase.h"

class CkBinData;
class CkJsonObject;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif


#undef Copy

// CLASS: CkPdf
class CK_VISIBLE_PUBLIC CkPdf  : public CkMultiByteBase
{
    private:

	// Don't allow assignment or copying these objects.
	CkPdf(const CkPdf &);
	CkPdf &operator=(const CkPdf &);

    public:
	CkPdf(void);
	virtual ~CkPdf(void);

	static CkPdf *createNew(void);
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	
		
	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// The PDF owner password to be used when loading a PDF into this object.
	void get_LoadOwnerPassword(CkString &str);
	// The PDF owner password to be used when loading a PDF into this object.
	const char *loadOwnerPassword(void);
	// The PDF owner password to be used when loading a PDF into this object.
	void put_LoadOwnerPassword(const char *newVal);

	// The PDF user password to be used when loading a PDF into this object.
	void get_LoadUserPassword(CkString &str);
	// The PDF user password to be used when loading a PDF into this object.
	const char *loadUserPassword(void);
	// The PDF user password to be used when loading a PDF into this object.
	void put_LoadUserPassword(const char *newVal);

	// The number of digital signatures present in the currently open PDF.
	int get_NumSignatures(void);

	// This is a catch-all property to be used for uncommon needs. This property
	// defaults to the empty string. Can be set to a list of the following comma
	// separated keywords:
	//     "WriteStandardXref" - When writing the PDF, write the cross reference
	//     section in standard format if possible. (The "standard format" is the older
	//     non-compressed format.)
	void get_UncommonOptions(CkString &str);
	// This is a catch-all property to be used for uncommon needs. This property
	// defaults to the empty string. Can be set to a list of the following comma
	// separated keywords:
	//     "WriteStandardXref" - When writing the PDF, write the cross reference
	//     section in standard format if possible. (The "standard format" is the older
	//     non-compressed format.)
	const char *uncommonOptions(void);
	// This is a catch-all property to be used for uncommon needs. This property
	// defaults to the empty string. Can be set to a list of the following comma
	// separated keywords:
	//     "WriteStandardXref" - When writing the PDF, write the cross reference
	//     section in standard format if possible. (The "standard format" is the older
	//     non-compressed format.)
	void put_UncommonOptions(const char *newVal);



	// ----------------------
	// Methods
	// ----------------------
	// Loads the PDF file contained in pdfData.
	bool LoadBd(CkBinData &pdfData);


	// Load a PDF file into this object in memory.
	bool LoadFile(const char *filePath);


	// Verifies the Nth signature contained in the PDF, where the 1st signature is
	// indicated by an index of 0. Returns true if the signature valid, otherwise
	// returns false. The sigInfo is an output argument and is populated with
	// information about the validated or unvalidated signature.
	bool VerifySignature(int index, CkJsonObject &sigInfo);






	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
