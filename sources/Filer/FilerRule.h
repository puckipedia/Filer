/*
	FilerRule.h: The main filing class for Filer. It holds a list of both test
					conditions and one or more actions to be performed should the
					conditions be met.
	Written by DarkWyrm <darkwyrm@gmail.com>, Copyright 2008
	Released under the MIT license.
*/
#ifndef FILER_RULE_H
#define FILER_RULE_H

#include <String.h>
#include <Entry.h>
#include <Archivable.h>
#include <Message.h>
#include "ObjectList.h"

typedef enum
{
	FILER_RULE_ALL = 0,
	FILER_RULE_ANY
} filer_rule_mode;


class FilerRule : public BArchivable
{
public:
								FilerRule(void);
								FilerRule(FilerRule &rule);
								~FilerRule(void);
			
			void				SetRuleMode(const filer_rule_mode &mode);
			filer_rule_mode		GetRuleMode(void) const { return fMode; }
			
			const char *		GetDescription(void) const;
			void				SetDescription(const char *desc);
			
			void				AddTest(BMessage *item, const int32 &index = -1);
			BMessage *			RemoveTest(const int32 &index);
			BMessage *			TestAt(const int32 &index);
			int32				CountTests(void) const;
			
			void				AddAction(BMessage *action, const int32 &index = -1);
			BMessage *			RemoveAction(const int32 &index);
			BMessage *			ActionAt(const int32 &index);
			int32				CountActions(void) const;
			
			void				MakeEmpty(void);
	virtual	void				PrintToStream(void);
			FilerRule &			operator=(FilerRule &from);
			
			int64				GetID(void) const { return fID; }
			
private:
	BObjectList<BMessage>		*fTestList;
	BObjectList<BMessage>		*fActionList;
	filer_rule_mode				fMode;
	BString						fDescription;
	int64						fID;
};

#endif
