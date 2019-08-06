import "types.cats"
import "restriction_account/account_restriction_types.cats"

# binary layout for account restrictions
struct AccountRestrictionsInfo
	# restriction type
	restrictionType = AccountRestrictionType

	# amount of restrictions for a particular account
	restrictionValuesCount = uint64

	# restrictions values
	restrictionValues = array(AccountRestrictionType, restrictionValuesCount)

# binary layout for account restrictions serializer
struct AccountRestrictions
	# address in which restrictions are placed
	address = Address

	# size of resrictions 
	restrictionsSize = uint64
	
	# restrictions to be serialized
	restrictions = AccountRestrictionsInfo
