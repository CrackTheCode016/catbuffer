import "types.cats"

# TODO fix this file

struct MosaicProperty

	id = uint32

# binary layout for mosaic definition
struct MosaicDefinition
	# block height
	height = Height

	# mosaic owner
	owner = Key

	# revision
	revision = uint32

	# number of elements in optional properties
	propertiesCount = uint8

	# optional properties
	properties = array(MosaicProperty, propertiesCount, sort_key=id)

# binary layout for mosaic entry serializer
struct MosaicEntry
	# entry id
	mosaicId = MosaicId

	# total supply amount
	supply = Amount

	# definition comprised of entry properties
	definition = MosaicDefinition
