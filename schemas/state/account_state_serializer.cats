import "types.cats"

# linked account type that indicates the account's link status
enum AccountType : uint8 
	unlinked = 0

	# account is a balance-holding account that is linked to a remote harvester account
	main = 1

	# account is a remote harvester account that is linked to a balance-holding account
	remote = 2

	# account is a remote harvester eligible account that is unlinked
	remoteUnlinked = 3

# binary layout for account balances
struct AccountBalance
	# mosaic id for balance
	mosaicId = MosaicId

	# optimized mosaic id
	optimizedMosaicId = MosaicId

	# balance amount
	balance = Amount


# binary layout for non-historical account state serializer
struct AccountState
	# address state
	address = Address

	# address state at block height
	addressHeight = Height

	# public key state
	publicKey = Key

	# public key state at block height
	publicKeyHeight = Height

	# link status
	type = AccountType

	# linked key
	linkedKey = Key

	# number of total balances (mosaics) owned
	balanceSize = uint64

	# state mosaic balances
	balances = array(AccountBalance, balanceSize)
