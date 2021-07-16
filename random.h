#include "generic.h"

#ifndef RANDOM_ENUMS
enum _vehicle {
	AUTOMOBILE,
	MOTORBIKE,
	SCOOTER,
	BUS,
	TRAIN,
	AIRPLANE,
	BOAT
};

enum _rank {
	PRIVATE,
	CORPORAL,
	SERGEANT,
	LIEUTENANT,
	CAPTAIN,
	MAJOR,
	COLONEL,
	GENERAL
};
#endif

// cult members :
typedef struct _cult_member {
	char *name;
	int age;
	int nationality;
	bool depressed;
	bool homeless;
	bool alcoholic;
	bool rich_parents;
	bool drug_addict;
	bool scared_of_commitment;
	bool unrealized_potential;
	bool sleep_disorder;
	bool eating_disorder;
	bool paranoia;
	male_specific_insecurities male;
	female_specific_insecurities female;
} cult_member;
typedef struct _male_specific_insecurities {
	bool small_dick;
	bool no_father;
	bool gay;
	bool feminine;
	bool jobless;
	bool sucks_at_math;
} male_specific_insecurities;
typedef struct _female_specific_insecurities {
	bool smelly_vagina;
	bool lesbian;
	bool masculine;
	bool ugly;
	bool raped;
	bool small_ass;
} female_specific_insecurities;

#define RANDOM_ENUMS 0
