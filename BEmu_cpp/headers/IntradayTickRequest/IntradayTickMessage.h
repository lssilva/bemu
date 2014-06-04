//------------------------------------------------------------------------------------------------
// <copyright project="BEmu_cpp" file="headers/IntradayTickRequest/IntradayTickMessage.h" company="Jordan Robinson">
//     Copyright (c) 2013 Jordan Robinson. All rights reserved.
//
//     The use of this software is governed by the Microsoft Public License
//     which is included with this distribution.
// </copyright>
//------------------------------------------------------------------------------------------------

#pragma once

#include <map>
#include "BloombergTypes/MessagePtr.h"

namespace BEmu
{
	class CorrelationId;
	class Service;
	class Datetime;
	class ElementPtr;

	namespace IntradayTickRequest
	{
		class IntradayTickElementDataParent;
		class IntradayTickElementResponseError;
		class IntradayTickElementTuple3;

		class IntradayTickMessage : public MessagePtr
		{
			private:
				boost::shared_ptr<IntradayTickElementDataParent> _parent;
				boost::shared_ptr<IntradayTickElementResponseError> _responseError;

				//IntradayTickElementDataParent *_parent;
				//IntradayTickElementResponseError *_responseError;

				bool _isResponseError;

			public:
				//IntradayTickMessage(const CorrelationId& corr, const Service& service, std::map<Datetime, IntradayTickElementTuple3*> *ticks, bool includeConditionCodes);
				IntradayTickMessage(const CorrelationId& corr, const Service& service, std::map<Datetime, boost::shared_ptr<IntradayTickElementTuple3>> *ticks, bool includeConditionCodes);

				IntradayTickMessage(const CorrelationId& corr, const Service& service);
				~IntradayTickMessage();

				//ElementPtr* firstElement() const;
				boost::shared_ptr<ElementPtr> firstElement() const;

				//virtual std::stack<ElementPtr*> getRootElements() const;
				virtual std::stack< boost::shared_ptr<ElementPtr> > getRootElements() const;

				virtual void markRootElementsDeleted();

				virtual const char* topicName() const;
				virtual size_t numElements() const;

				//virtual ElementPtr * asElement() const;
				virtual boost::shared_ptr<ElementPtr> asElement() const;
				
				//virtual ElementPtr * getElement(const char* name) const;
				virtual boost::shared_ptr<ElementPtr> getElement(const char* name) const;
				
				virtual bool hasElement(const char* name, bool excludeNullElements = false) const;

				virtual std::ostream& print(std::ostream& stream, int level = 0, int spacesPerLevel = 4) const;
		};
	}
}