#ifndef TYPED_REF_FILTER
#define TYPED_REF_FILTER

#include <FilePanel.h>
#include <String.h>

/*
	This utility class is for filtering 
*/
class TypedRefFilter : public BRefFilter
{
public:
							TypedRefFilter(void);
							TypedRefFilter(const char *file_type,
											const uint32 &node_type = B_FILE_NODE |
																	B_DIRECTORY_NODE |
																	B_SYMLINK_NODE);
	virtual 				~TypedRefFilter(void);
	
			const char *	FileType(void) const;
			void			SetFileType(const char *type);
	
			uint32			NodeType(void) const;
			void			SetNodeType(const uint32 &node_type);
	
	virtual bool			Filter(const entry_ref *ref, BNode *node,
									struct stat *st, const char *filetype);
	
	
private:
			BString			fFileType;
			uint32			fNodeType;
};

#endif
