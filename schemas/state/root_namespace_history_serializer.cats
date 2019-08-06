import "namespace/namespace_types.cats"
import "mosaic/mosaic_definition.cats"


# binary layout for namespace lifetime
struct NamespaceLifetime
	# lifetime start
	lifetimeStart = Height

	# lifetime end
	lifetimeEnd = Height

# namespace alias type 
enum AliasType : uint8
	# if alias is mosaicId
	mosaicId = 0

	# if alias is address
	address = 1

# binary layout for non-historical root namespace history serializer
struct RootNamespaceHistory

	# root owner
	owner = Key

	# root id 
	namespaceId = NamespaceId

	# alias type
	aliasType = AliasType

	# lifetime in blocks
	lifetime = NamespaceLifetime

	# if mosaic id alias, assign AliasType as MosaicId
	mosaicAlias = MosaicId if aliasType equals mosaicId

	# if address alias, assign AliasType as Address
	addressAlias = Address if aliasType equals address

	# max child depth
	childMaxDepth = int8

	# child paths
	childPaths = array(NamespaceId, size=childMaxDepth)	
