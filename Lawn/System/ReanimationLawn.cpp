#include "../Plant.h"
#include "../Zombie.h"
#include "../../LawnApp.h"
#include "ReanimationLawn.h"
#include "../../Sexy.TodLib/TodDebug.h"
#include "../../SexyAppFramework/Color.h"
#include "../../Sexy.TodLib/Reanimator.h"
#include "../../SexyAppFramework/MemoryImage.h"
#ifdef DO_FIX_BUGS
#include "../../Resources.h"
#endif
#include "../../Sexy.TodLib/FilterEffect.h"

//0x46EF00
void ReanimatorCache::UpdateReanimationForVariation(Reanimation* theReanim, DrawVariation theDrawVariation, DrawFilterVariation theFilterVariation)
{
	if (theDrawVariation >= DrawVariation::VARIATION_MARIGOLD_WHITE && theDrawVariation <= DrawVariation::VARIATION_MARIGOLD_LIGHT_GREEN)
	{
		int aVariationIndex = (int)theDrawVariation - (int)DrawVariation::VARIATION_MARIGOLD_WHITE;
		Color MARIGOLD_VARIATIONS[] = {
			Color(255, 255, 255),
			Color(230, 30, 195),
			Color(250, 125, 5),
			Color(255, 145, 215),
			Color(160, 255, 245),
			Color(230, 30, 30),
			Color(5, 130, 255),
			Color(195, 55, 235),
			Color(235, 210, 255),
			Color(255, 245, 55),
			Color(180, 255, 105)
		};

		TOD_ASSERT(aVariationIndex >= 0 && aVariationIndex < LENGTH(MARIGOLD_VARIATIONS));
		theReanim->GetTrackInstanceByName("Marigold_petals")->mTrackColor = MARIGOLD_VARIATIONS[aVariationIndex];
	}
	else
	{
		switch (theDrawVariation)
		{
		/*case DrawVariation::VARIATION_IMITATER:
		{
			theReanim->mFilterEffect = FilterEffect::FILTER_EFFECT_WASHED_OUT;
			break;
		}	
		case DrawVariation::VARIATION_IMITATER_LESS:
		{
			theReanim->mFilterEffect = FilterEffect::FILTER_EFFECT_LESS_WASHED_OUT;
			break;
		}*/
		case DrawVariation::VARIATION_ZEN_GARDEN:
			theReanim->SetFramesForLayer("anim_zengarden");
			break;
		case DrawVariation::VARIATION_ZEN_GARDEN_WATER:
			theReanim->SetFramesForLayer("anim_waterplants");
			break;
		case DrawVariation::VARIATION_AQUARIUM:
			theReanim->SetFramesForLayer("anim_idle_aquarium");
			break;
		case DrawVariation::VARIATION_SPROUT_NO_FLOWER:
			theReanim->SetFramesForLayer("anim_idle_noflower");
			break;
		case DrawVariation::VARIATION_PUMPKINSHELL_FRONT:
			theReanim->AssignRenderGroupToPrefix("Pumpkin_back", RENDER_GROUP_HIDDEN);
			break;
		case DrawVariation::VARIATION_PUMPKINSHELL_BACK:
			theReanim->AssignRenderGroupToPrefix("Pumpkin_front", RENDER_GROUP_HIDDEN);
			break;
		case DrawVariation::VARIATION_NORMAL_DEGRADE1:
		case DrawVariation::VARIATION_NORMAL_DEGRADE2:
		{
			if (theReanim->mReanimationType == REANIM_WALLNUT)
			{
				if (theDrawVariation == DrawVariation::VARIATION_NORMAL_DEGRADE1 || theDrawVariation == DrawVariation::VARIATION_NORMAL_DEGRADE2) {
					Image* aOverride = theDrawVariation == DrawVariation::VARIATION_NORMAL_DEGRADE1 ? IMAGE_REANIM_WALLNUT_CRACKED1 : IMAGE_REANIM_WALLNUT_CRACKED2;
					theReanim->SetImageOverride("anim_face", aOverride);
				}
			}
			else if (theReanim->mReanimationType == REANIM_TALLNUT)
			{
				if (theDrawVariation == DrawVariation::VARIATION_NORMAL_DEGRADE1 || theDrawVariation == DrawVariation::VARIATION_NORMAL_DEGRADE2) {
					Image* aOverride = theDrawVariation == DrawVariation::VARIATION_NORMAL_DEGRADE1 ? IMAGE_REANIM_TALLNUT_CRACKED1 : IMAGE_REANIM_TALLNUT_CRACKED2;
					theReanim->SetImageOverride("anim_idle", aOverride);
				}
			}
			else if (theReanim->mReanimationType == REANIM_PUMPKIN)
			{
				if (theDrawVariation == DrawVariation::VARIATION_NORMAL_DEGRADE1 || theDrawVariation == DrawVariation::VARIATION_NORMAL_DEGRADE2) {
					Image* aOverride = theDrawVariation == DrawVariation::VARIATION_NORMAL_DEGRADE1 ? IMAGE_REANIM_PUMPKIN_DAMAGE1 : IMAGE_REANIM_PUMPKIN_DAMAGE3;
					theReanim->SetImageOverride("Pumpkin_front", aOverride);
				}
			}
			else if (theReanim->mReanimationType == REANIM_GARLIC)
			{
				if (theDrawVariation == DrawVariation::VARIATION_NORMAL_DEGRADE1 || theDrawVariation == DrawVariation::VARIATION_NORMAL_DEGRADE2) {
					Image* aOverride = theDrawVariation == DrawVariation::VARIATION_NORMAL_DEGRADE1 ? IMAGE_REANIM_GARLIC_BODY2 : IMAGE_REANIM_GARLIC_BODY3;
					theReanim->SetImageOverride("anim_face", aOverride);
				}
			}
			else if (theReanim->mReanimationType == REANIM_SPIKEROCK)
			{
				if (theDrawVariation == DrawVariation::VARIATION_NORMAL_DEGRADE1)
				{
					theReanim->AssignRenderGroupToTrack("bigspike2", RENDER_GROUP_HIDDEN);
					theReanim->AssignRenderGroupToTrack("bigspike3", RENDER_GROUP_HIDDEN);
				}
				if (theDrawVariation == DrawVariation::VARIATION_NORMAL_DEGRADE2)
				{
					theReanim->AssignRenderGroupToTrack("bigspike1", RENDER_GROUP_HIDDEN);
					theReanim->AssignRenderGroupToTrack("bigspike2", RENDER_GROUP_HIDDEN);
					theReanim->AssignRenderGroupToTrack("bigspike3", RENDER_GROUP_HIDDEN);
				}
			}
			break;
		}
		case DrawVariation::VARIATION_KERNELPULT_WITH_BUTTER:
		case DrawVariation::VARIATION_SUNSHROOM_BIG:
			break;
		case DrawVariation::VARIATION_PUMPKINSHELL_FRONT_DEGRADE1:
		case DrawVariation::VARIATION_PUMPKINSHELL_FRONT_DEGRADE2:
		{
			theReanim->AssignRenderGroupToPrefix("Pumpkin_back", RENDER_GROUP_HIDDEN);
			Image* aOverride = theDrawVariation == DrawVariation::VARIATION_PUMPKINSHELL_FRONT_DEGRADE1 ? IMAGE_REANIM_PUMPKIN_DAMAGE1 : IMAGE_REANIM_PUMPKIN_DAMAGE3;
			theReanim->SetImageOverride("Pumpkin_front", aOverride);
			break;
		}
		default:
			TOD_ASSERT(false);
			break;
		}
	}
}

//0x46F100
void ReanimatorCache::DrawReanimatorFrame(Graphics* g, float thePosX, float thePosY, ReanimationType theReanimationType, const char* theTrackName, DrawVariation theDrawVariation, DrawFilterVariation theFilterVariation, unsigned int theDrawBitVariation)
{
	Reanimation aReanim;
	aReanim.ReanimationInitializeType(thePosX, thePosY, theReanimationType);

	if (theTrackName != nullptr && aReanim.TrackExists(theTrackName))
	{
		aReanim.SetFramesForLayer(theTrackName);
	}

	if (theReanimationType == ReanimationType::REANIM_KERNELPULT && theDrawVariation != DrawVariation::VARIATION_KERNELPULT_WITH_BUTTER)
	{
		aReanim.AssignRenderGroupToTrack("Cornpult_butter", RENDER_GROUP_HIDDEN);
	}
	else if (theReanimationType == ReanimationType::REANIM_SUNFLOWER)
	{
		aReanim.mAnimTime = 0.15f;
	}
	aReanim.AssignRenderGroupToTrack("anim_waterline", RENDER_GROUP_HIDDEN);

	if (g->GetColorizeImages())
	{
		aReanim.mColorOverride = g->GetColor();
	}
	aReanim.OverrideScale(g->mScaleX, g->mScaleY);
	
	if (theDrawVariation != DrawVariation::VARIATION_NORMAL)
	{
		UpdateReanimationForVariation(&aReanim, theDrawVariation);
	}

	if (theFilterVariation != DrawFilterVariation::FILTERVARIATION_NONE)
	{
		switch (theFilterVariation)
		{
		case DrawFilterVariation::FILTERVARIATION_WASHED_OUT:
			aReanim.mFilterEffect = FilterEffect::FILTER_EFFECT_WASHED_OUT;
			break;
		case DrawFilterVariation::FILTERVARIATION_LESS_WASHED_OUT:
			aReanim.mFilterEffect = FilterEffect::FILTER_EFFECT_LESS_WASHED_OUT;
			break;
		case DrawFilterVariation::FILTERVARIATION_WHITE:
			aReanim.mFilterEffect = FilterEffect::FILTER_EFFECT_LESS_WASHED_OUT;
			break;
		}
	}

	if (TestBit(theDrawBitVariation, (int)DrawBitVariation::BITVARIATION_IZOMBIE))
	{
		g->SetColorizeImages(true);
		aReanim.mFilterEffect = FilterEffect::FILTER_EFFECT_WHITE;

		float aOffsetX = g->mTransX, aOffsetY = g->mTransY;
		g->mTransX = aOffsetX + 4;
		g->mTransY = aOffsetY + 4;
		g->SetColor(Color(122, 86, 58));
		aReanim.Draw(g);

		g->mTransX = aOffsetX + 2;
		g->mTransY = aOffsetY + 2;
		g->SetColor(Color(171, 135, 107));
		aReanim.Draw(g);

		g->mTransX = aOffsetX - 2;
		g->mTransY = aOffsetY - 2;
		g->SetColor(Color(171, 135, 107));
		aReanim.Draw(g);

		g->mTransX = aOffsetX;
		g->mTransY = aOffsetY;
		g->SetColor(Color(255, 201, 160));
		aReanim.mFilterEffect = FilterEffect::FILTER_EFFECT_NONE;
		aReanim.Draw(g);
		g->SetDrawMode(Graphics::DRAWMODE_NORMAL);
		g->SetColorizeImages(false);
	}
	else
	{
		aReanim.Draw(g);
	}
}

//0x46F280
MemoryImage* ReanimatorCache::MakeBlankMemoryImage(int theWidth, int theHeight)
{
	MemoryImage* aImage = new MemoryImage();

	int aBitsCount = theWidth * theHeight;
	aImage->mBits = new unsigned long[aBitsCount + 1];
	aImage->mWidth = theWidth;
	aImage->mHeight = theHeight;
	aImage->mHasTrans = true;
	aImage->mHasAlpha = true;
	memset(aImage->mBits, 0, aBitsCount * 4);
	aImage->mBits[aBitsCount] = Sexy::MEMORYCHECK_ID;
	return aImage;
}

void ReanimatorCache::GetPlantImageSize(SeedType theSeedType, int& theOffsetX, int& theOffsetY, int& theWidth, int& theHeight)
{
	theOffsetX = -20;
	theOffsetY = -20;
	theWidth = 120;
	theHeight = 120;

	if (theSeedType == SeedType::SEED_TALLNUT)
	{
		theOffsetY = -40;
		theHeight += 40;
	}
	else if (theSeedType == SeedType::SEED_MELONPULT || theSeedType == SeedType::SEED_WINTERMELON)
	{
		theOffsetX = -40;
		theWidth += 40;
	}
	else if (theSeedType == SeedType::SEED_COBCANNON)
	{
		theWidth += 80;
	}
}

//0x46F330
MemoryImage* ReanimatorCache::MakeCachedMowerFrame(LawnMowerType theMowerType)
{
	MemoryImage* aImage;

	switch (theMowerType)
	{
	case LawnMowerType::LAWNMOWER_LAWN:
	{
		aImage = MakeBlankMemoryImage(90, 100);
		Graphics aMemoryGraphics(aImage);
		aMemoryGraphics.SetLinearBlend(true);
		aMemoryGraphics.mScaleX = 0.85f;
		aMemoryGraphics.mScaleY = 0.85f;
		DrawReanimatorFrame(&aMemoryGraphics, 10.0f, 0.0f, ReanimationType::REANIM_LAWNMOWER, "anim_normal", DrawVariation::VARIATION_NORMAL);
		break;
	}
	case LawnMowerType::LAWNMOWER_POOL:
	{
		aImage = MakeBlankMemoryImage(90, 100);
		Graphics aMemoryGraphics(aImage);
		aMemoryGraphics.SetLinearBlend(true);
		aMemoryGraphics.mScaleX = 0.8f;
		aMemoryGraphics.mScaleY = 0.8f;
		DrawReanimatorFrame(&aMemoryGraphics, 10.0f, 25.0f, ReanimationType::REANIM_POOL_CLEANER, nullptr, DrawVariation::VARIATION_NORMAL);
		break;
	}
	case LawnMowerType::LAWNMOWER_ROOF:
	{
		aImage = MakeBlankMemoryImage(90, 100);
		Graphics aMemoryGraphics(aImage);
		aMemoryGraphics.SetLinearBlend(true);
		aMemoryGraphics.mScaleX = 0.85f;
		aMemoryGraphics.mScaleY = 0.85f;
		DrawReanimatorFrame(&aMemoryGraphics, 10.0f, 0.0f, ReanimationType::REANIM_ROOF_CLEANER, nullptr, DrawVariation::VARIATION_NORMAL);
		break;
	}
	case LawnMowerType::LAWNMOWER_SUPER_MOWER:
	{
		aImage = MakeBlankMemoryImage(90, 100);
		Graphics aMemoryGraphics(aImage);
		aMemoryGraphics.SetLinearBlend(true);
		aMemoryGraphics.mScaleX = 0.85f;
		aMemoryGraphics.mScaleY = 0.85f;
		DrawReanimatorFrame(&aMemoryGraphics, 10.0f, 0.0f, ReanimationType::REANIM_LAWNMOWER, "anim_tricked", DrawVariation::VARIATION_NORMAL);
		break;
	}
	default:
		TOD_ASSERT(false);
		break;
	}

	return aImage;
}

//0x46F550
MemoryImage* ReanimatorCache::MakeCachedPlantFrame(SeedType theSeedType, DrawVariation theDrawVariation, DrawFilterVariation theFilterVariation, unsigned int theDrawBitVariation)
{
	int aOffsetX, aOffsetY, aWidth, aHeight;
	GetPlantImageSize(theSeedType, aOffsetX, aOffsetY, aWidth, aHeight);
	MemoryImage* aMemoryImage = MakeBlankMemoryImage(aWidth, aHeight);
	Graphics aMemoryGraphics(aMemoryImage);
	aMemoryGraphics.SetLinearBlend(true);

	PlantDefinition& aPlantDef = GetPlantDefinition(theSeedType);
	TOD_ASSERT(aPlantDef.mReanimationType != ReanimationType::REANIM_NONE);

	if (theSeedType == SeedType::SEED_POTATOMINE)
	{
		aMemoryGraphics.mScaleX = 0.85f;
		aMemoryGraphics.mScaleY = 0.85f;
		DrawReanimatorFrame(&aMemoryGraphics, -(int)(aOffsetX - 12.0f), -(int)(aOffsetY - 12.0f), aPlantDef.mReanimationType, "anim_armed", theDrawVariation, theFilterVariation, theDrawBitVariation);
	}
	else if (theSeedType == SeedType::SEED_INSTANT_COFFEE)
	{
		aMemoryGraphics.mScaleX = 0.8f;
		aMemoryGraphics.mScaleY = 0.8f;
		DrawReanimatorFrame(&aMemoryGraphics, -(int)(aOffsetX - 12.0f), -(int)(aOffsetY - 12.0f), aPlantDef.mReanimationType, "anim_idle", theDrawVariation, theFilterVariation, theDrawBitVariation);
	}
	else if (theSeedType == SeedType::SEED_EXPLODE_O_NUT)
	{
		aMemoryGraphics.SetColorizeImages(true);
		aMemoryGraphics.SetColor(Color(255, 64, 64));
		DrawReanimatorFrame(&aMemoryGraphics, -aOffsetX, -aOffsetY, aPlantDef.mReanimationType, "anim_idle", theDrawVariation, theFilterVariation, theDrawBitVariation);
	}
	else if (theDrawVariation == DrawVariation::VARIATION_SUNSHROOM_BIG)
	{
		DrawReanimatorFrame(&aMemoryGraphics, -aOffsetX, -aOffsetY, aPlantDef.mReanimationType, "anim_bigidle", theDrawVariation, theFilterVariation, theDrawBitVariation);
	}
	else
	{
		DrawReanimatorFrame(&aMemoryGraphics, -aOffsetX, -aOffsetY, aPlantDef.mReanimationType, "anim_idle", theDrawVariation, theFilterVariation, theDrawBitVariation);

		if (theSeedType == SeedType::SEED_PEASHOOTER || theSeedType == SeedType::SEED_SNOWPEA || theSeedType == SeedType::SEED_REPEATER ||
			theSeedType == SeedType::SEED_LEFTPEATER || theSeedType == SeedType::SEED_GATLINGPEA)
		{
			DrawReanimatorFrame(&aMemoryGraphics, -aOffsetX, -aOffsetY, aPlantDef.mReanimationType, "anim_head_idle", theDrawVariation, theFilterVariation, theDrawBitVariation);
		}
		else if (theSeedType == SeedType::SEED_SPLITPEA)
		{
			DrawReanimatorFrame(&aMemoryGraphics, -aOffsetX, -aOffsetY, aPlantDef.mReanimationType, "anim_head_idle", theDrawVariation, theFilterVariation, theDrawBitVariation);
			DrawReanimatorFrame(&aMemoryGraphics, -aOffsetX, -aOffsetY, aPlantDef.mReanimationType, "anim_splitpea_idle", theDrawVariation, theFilterVariation, theDrawBitVariation);
		}
		else if (theSeedType == SeedType::SEED_THREEPEATER)
		{
			DrawReanimatorFrame(&aMemoryGraphics, -aOffsetX, -aOffsetY, aPlantDef.mReanimationType, "anim_head_idle1", theDrawVariation, theFilterVariation, theDrawBitVariation);
			DrawReanimatorFrame(&aMemoryGraphics, -aOffsetX, -aOffsetY, aPlantDef.mReanimationType, "anim_head_idle3", theDrawVariation, theFilterVariation, theDrawBitVariation);
			DrawReanimatorFrame(&aMemoryGraphics, -aOffsetX, -aOffsetY, aPlantDef.mReanimationType, "anim_head_idle2", theDrawVariation, theFilterVariation, theDrawBitVariation);
		}
	}

	return aMemoryImage;
}

//0x46F8A0
MemoryImage* ReanimatorCache::MakeCachedZombieFrame(ZombieType theZombieType)
{
	int maxWidth = 200;
	int maxHeight = 210;

	if (theZombieType == ZombieType::ZOMBIE_ZAMBONI)	maxWidth = 300;
	if (theZombieType == ZombieType::ZOMBIE_CACHED_POLEVAULTER_WITH_POLE)	maxWidth = 250;
	if (theZombieType == ZombieType::ZOMBIE_BUNGEE) maxHeight = 810;

	MemoryImage* aMemoryImage = MakeBlankMemoryImage(maxWidth, maxHeight);
	Graphics aMemoryGraphics(aMemoryImage);
	aMemoryGraphics.SetLinearBlend(true);

	ZombieType aUseZombieType = theZombieType;
	if (theZombieType == ZombieType::ZOMBIE_CACHED_POLEVAULTER_WITH_POLE)
	{
		aUseZombieType = ZombieType::ZOMBIE_POLEVAULTER;
	}
	ZombieDefinition& aZombieDef = GetZombieDefinition(aUseZombieType);
	TOD_ASSERT(aZombieDef.mReanimationType != ReanimationType::REANIM_NONE);

	float aPosX = 40.0f, aPosY = 40.0f;
	if (aZombieDef.mReanimationType == ReanimationType::REANIM_ZOMBIE)
	{
		Reanimation aReanim;
		aReanim.ReanimationInitializeType(aPosX, aPosY, aZombieDef.mReanimationType);
		aReanim.SetFramesForLayer("anim_idle");
		Zombie::SetupReanimLayers(&aReanim, aUseZombieType);

		if (theZombieType == ZombieType::ZOMBIE_DOOR)
		{
			aReanim.AssignRenderGroupToTrack("anim_screendoor", RENDER_GROUP_NORMAL);
			aReanim.AssignRenderGroupToTrack("Zombie_outerarm_screendoor", RENDER_GROUP_NORMAL);
		}
		else if (theZombieType == ZombieType::ZOMBIE_FLAG)
		{
			Reanimation aReanimFlag;
			aReanimFlag.ReanimationInitializeType(aPosX, aPosY, ReanimationType::REANIM_FLAG);
			aReanimFlag.SetFramesForLayer("Zombie_flag");
			aReanimFlag.Draw(&aMemoryGraphics);
		}
		aReanim.Draw(&aMemoryGraphics);
	}
	else if (aZombieDef.mReanimationType == ReanimationType::REANIM_BOSS)
	{
		Reanimation aReanim;
		aReanim.ReanimationInitializeType(-524.0f, -88.0f, aZombieDef.mReanimationType);
		aReanim.SetFramesForLayer("anim_head_idle");
		Reanimation aReanimDriver;
		aReanimDriver.ReanimationInitializeType(46.0f, 22.0f, ReanimationType::REANIM_BOSS_DRIVER);
		aReanimDriver.SetFramesForLayer("anim_idle");

		aReanim.Draw(&aMemoryGraphics);
		aReanimDriver.Draw(&aMemoryGraphics);
		aReanim.AssignRenderGroupToTrack("boss_body1", RENDER_GROUP_HIDDEN);
		aReanim.AssignRenderGroupToTrack("boss_neck", RENDER_GROUP_HIDDEN);
		aReanim.AssignRenderGroupToTrack("boss_head2", RENDER_GROUP_HIDDEN);
		aReanim.Draw(&aMemoryGraphics);
	}
	else if (theZombieType == ZombieType::ZOMBIE_BALLOON)
	{
		Reanimation aReanim;
		aReanim.ReanimationInitializeType(aPosX, aPosY, aZombieDef.mReanimationType);
		Reanimation aPropellerReanim;
		aPropellerReanim.ReanimationInitializeType(aPosX, aPosY, aZombieDef.mReanimationType);
		aPropellerReanim.SetFramesForLayer("Propeller");
		aPropellerReanim.mLoopType = ReanimLoopType::REANIM_LOOP_FULL_LAST_FRAME;

		aReanim.Draw(&aMemoryGraphics);
		aPropellerReanim.Draw(&aMemoryGraphics);
	}
	else if (theZombieType == ZombieType::ZOMBIE_BUNGEE)
	{
		Reanimation aReanim;
		int relativeY = maxHeight - 210;
		aReanim.ReanimationInitializeType(aPosX, aPosY, aZombieDef.mReanimationType);

		int aCordCelHeight = IMAGE_BUNGEECORD->GetCelHeight();
		int iterat = 0;
		for (float y = maxHeight + 210 - aCordCelHeight; y > -aCordCelHeight; y -= aCordCelHeight)
		{
			aMemoryGraphics.DrawImageF(IMAGE_BUNGEECORD, 61.0f - 4.0f + 22, -iterat * aCordCelHeight - 14 + relativeY);
			iterat++;
		}

		MemoryImage* aMemoryImage2 = MakeBlankMemoryImage(200, 210);
		Graphics aMemoryGraphics2(aMemoryImage2);
		aMemoryGraphics2.SetLinearBlend(true);
		aReanim.Draw(&aMemoryGraphics2);
		aMemoryGraphics.DrawImageF(aMemoryImage2, 0, relativeY);
	}
	else if (theZombieType == ZombieType::ZOMBIE_DANCER)
	{
		Reanimation aReanim;
		aReanim.OverrideScale(0.79872f, 0.79872f);
		aPosX += 8;
		aPosY += 32;

		aReanim.ReanimationInitializeType(aPosX, aPosY, aZombieDef.mReanimationType);
		aReanim.PlayReanim("anim_moonwalk", ReanimLoopType::REANIM_PLAY_ONCE_AND_HOLD, 0, 24.0f);
		aReanim.Draw(&aMemoryGraphics);
	}
	else if (theZombieType == ZombieType::ZOMBIE_BACKUP_DANCER)
	{
		Reanimation aReanim;
		aReanim.OverrideScale(0.79872f, 0.79872f);
		aPosX += 8;
		aPosY += 32;

		aReanim.ReanimationInitializeType(aPosX, aPosY, aZombieDef.mReanimationType);
		aReanim.PlayReanim("anim_armraise", ReanimLoopType::REANIM_PLAY_ONCE_AND_HOLD, 0, 24.0f);
		aReanim.mAnimTime = 0.5f;
		aReanim.Draw(&aMemoryGraphics);
	}
	else if (theZombieType == ZombieType::ZOMBIE_BOBSLED)
	{
		{
			aMemoryGraphics.DrawImageF(IMAGE_ZOMBIE_BOBSLED_INSIDE, -55, 80);
		}

		{
			Reanimation aReanim;
			aPosX = 40.0f;
			aPosY = 30.0f;
			aReanim.ReanimationInitializeType(aPosX, aPosY, aZombieDef.mReanimationType);
			aReanim.PlayReanim("anim_jump", ReanimLoopType::REANIM_PLAY_ONCE_AND_HOLD, 0, 20.0f);
			aReanim.mAnimTime = 1.0f;
			aReanim.Draw(&aMemoryGraphics);
		}

		{
			Reanimation aReanim;
			aPosX = 90.0f;
			aPosY = 30.0f;
			aReanim.ReanimationInitializeType(aPosX, aPosY, aZombieDef.mReanimationType);
			aReanim.PlayReanim("anim_jump", ReanimLoopType::REANIM_PLAY_ONCE_AND_HOLD, 0, 20.0f);
			aReanim.mAnimTime = 1.0f;
			aReanim.Draw(&aMemoryGraphics);
		}

		{
			Reanimation aReanim;
			aPosX = 140.0f;
			aPosY = 30.0f;
			aReanim.ReanimationInitializeType(aPosX, aPosY, aZombieDef.mReanimationType);
			aReanim.PlayReanim("anim_jump", ReanimLoopType::REANIM_PLAY_ONCE_AND_HOLD, 0, 20.0f);
			aReanim.mAnimTime = 1.0f;
			aReanim.Draw(&aMemoryGraphics);
		}

		{
			Reanimation aReanim;
			aPosX = 190.0f;
			aPosY = 30.0f;
			aReanim.ReanimationInitializeType(aPosX, aPosY, aZombieDef.mReanimationType);
			aReanim.PlayReanim("anim_jump", ReanimLoopType::REANIM_PLAY_ONCE_AND_HOLD, 0, 20.0f);
			aReanim.mAnimTime = 1.0f;
			aReanim.Draw(&aMemoryGraphics);
		}

		{
			aMemoryGraphics.DrawImageF(IMAGE_ZOMBIE_BOBSLED1, -55, 80);
		}
	}
	else
	{
		const char* aTrackName = "anim_idle";
		if (theZombieType == ZombieType::ZOMBIE_POGO)
		{
			aTrackName = "anim_pogo";
		}
		else if (theZombieType == ZombieType::ZOMBIE_CACHED_POLEVAULTER_WITH_POLE)
		{
			aTrackName = "anim_idle";
			aPosX += 50;
		}
		else if (theZombieType == ZombieType::ZOMBIE_POLEVAULTER)
		{
			aTrackName = "anim_walk";
		}
		else if (theZombieType == ZombieType::ZOMBIE_GARGANTUAR)
		{
			aPosY = 60.0f;
		}
		else if (theZombieType == ZombieType::ZOMBIE_ZAMBONI)
		{
			aPosX += 50;
		}

		DrawReanimatorFrame(&aMemoryGraphics, aPosX, aPosY, aZombieDef.mReanimationType, aTrackName, DrawVariation::VARIATION_NORMAL, DrawFilterVariation::FILTERVARIATION_NONE, DrawBitVariation::BITVARIATION_NONE);
	}
	return aMemoryImage;
}

//0x46FDC0
void ReanimatorCache::ReanimatorCacheInitialize()
{
	mApp = (LawnApp*)gSexyAppBase;
	for (int i = 0; i < SeedType::NUM_SEED_TYPES; i++)
		mPlantImages[i] = nullptr;
	for (int i = 0; i < LawnMowerType::NUM_MOWER_TYPES; i++)
		mLawnMowers[i] = nullptr;
	for (int i = 0; i < ZombieType::NUM_ZOMBIE_TYPES; i++)
		mZombieImages[i] = nullptr;
}

//0x46FED0
void ReanimatorCache::ReanimatorCacheDispose()
{
	for (int i = 0; i < SeedType::NUM_SEED_TYPES; i++)
		delete mPlantImages[i];
	while (mImageVariationList.mSize != 0)
	{
		ReanimCacheImageVariation aImageVariation = mImageVariationList.RemoveHead();
		if (aImageVariation.mImage != nullptr)
			delete aImageVariation.mImage;
	}
	for (int i = 0; i < LawnMowerType::NUM_MOWER_TYPES; i++)
		delete mLawnMowers[i];
	for (int i = 0; i < ZombieType::NUM_ZOMBIE_TYPES; i++)
		delete mZombieImages[i];
}


//0x46FFB0
void ReanimatorCache::DrawCachedPlant(Graphics* g, float thePosX, float thePosY, SeedType theSeedType, DrawVariation theDrawVariation, DrawFilterVariation theFilterVariation, unsigned int theDrawBitVariation)
{
	TOD_ASSERT(theSeedType >= 0 && theSeedType < SeedType::NUM_SEED_TYPES);

	MemoryImage* aImage = nullptr;
	if (theDrawVariation != DrawVariation::VARIATION_NORMAL)
	{
		for (TodListNode<ReanimCacheImageVariation>* aNode = mImageVariationList.mHead; aNode != nullptr; aNode = aNode->mNext)
		{
			ReanimCacheImageVariation& aImageVariation = aNode->mValue;
			if (aImageVariation.mSeedType == theSeedType && aImageVariation.mDrawVariation == theDrawVariation && aImageVariation.mFilterVariation == theFilterVariation &&
				aImageVariation.mDrawBitVariation == theDrawBitVariation)
			{
				aImage = aImageVariation.mImage;
				break;
			}
		}

		if (aImage == nullptr)
		{
			aImage = MakeCachedPlantFrame(theSeedType, theDrawVariation, theFilterVariation, theDrawBitVariation);
			ReanimCacheImageVariation aNewImageVariation;
			aNewImageVariation.mSeedType = theSeedType;
			aNewImageVariation.mDrawVariation = theDrawVariation;
			aNewImageVariation.mFilterVariation = theFilterVariation;
			aNewImageVariation.mDrawBitVariation = theDrawBitVariation;
			aNewImageVariation.mImage = aImage;
			mImageVariationList.AddHead(aNewImageVariation);
		}
	}
	else if (theFilterVariation != DrawFilterVariation::FILTERVARIATION_NONE)
	{
		for (TodListNode<ReanimCacheImageVariation>* aNode = mImageVariationList.mHead; aNode != nullptr; aNode = aNode->mNext)
		{
			ReanimCacheImageVariation& aImageVariation = aNode->mValue;
			if (aImageVariation.mSeedType == theSeedType && aImageVariation.mDrawVariation == DrawVariation::VARIATION_NORMAL && aImageVariation.mFilterVariation == theFilterVariation &&
				aImageVariation.mDrawBitVariation == theDrawBitVariation)
			{
				aImage = aImageVariation.mImage;
				break;
			}
		}

		if (aImage == nullptr)
		{
			aImage = MakeCachedPlantFrame(theSeedType, DrawVariation::VARIATION_NORMAL, theFilterVariation, theDrawBitVariation);
			ReanimCacheImageVariation aNewImageVariation;
			aNewImageVariation.mSeedType = theSeedType;
			aNewImageVariation.mDrawVariation = DrawVariation::VARIATION_NORMAL;
			aNewImageVariation.mFilterVariation = theFilterVariation;
			aNewImageVariation.mDrawBitVariation = theDrawBitVariation;
			aNewImageVariation.mImage = aImage;
			mImageVariationList.AddHead(aNewImageVariation);
		}
	}
	else if (theDrawBitVariation != DrawBitVariation::BITVARIATION_NONE)
	{
		for (TodListNode<ReanimCacheImageVariation>* aNode = mImageVariationList.mHead; aNode != nullptr; aNode = aNode->mNext)
		{
			ReanimCacheImageVariation& aImageVariation = aNode->mValue;
			if (aImageVariation.mSeedType == theSeedType && aImageVariation.mDrawVariation == DrawVariation::VARIATION_NORMAL && 
				aImageVariation.mFilterVariation == DrawFilterVariation::FILTERVARIATION_NONE && aImageVariation.mDrawBitVariation == theDrawBitVariation)
			{
				aImage = aImageVariation.mImage;
				break;
			}
		}

		if (aImage == nullptr)
		{
			aImage = MakeCachedPlantFrame(theSeedType, DrawVariation::VARIATION_NORMAL, theFilterVariation, theDrawBitVariation);
			ReanimCacheImageVariation aNewImageVariation;
			aNewImageVariation.mSeedType = theSeedType;
			aNewImageVariation.mDrawVariation = DrawVariation::VARIATION_NORMAL;
			aNewImageVariation.mFilterVariation = DrawFilterVariation::FILTERVARIATION_NONE;
			aNewImageVariation.mDrawBitVariation = theDrawBitVariation;
			aNewImageVariation.mImage = aImage;
			mImageVariationList.AddHead(aNewImageVariation);
		}
	}
	else
	{
		aImage = mPlantImages[(int)theSeedType];
		if (aImage == nullptr)
		{
			aImage = MakeCachedPlantFrame(theSeedType, DrawVariation::VARIATION_NORMAL, DrawFilterVariation::FILTERVARIATION_NONE);
			mPlantImages[(int)theSeedType] = aImage;
		}
	}

	int aOffsetX, aOffsetY, aWidth, aHeight;
	GetPlantImageSize(theSeedType, aOffsetX, aOffsetY, aWidth, aHeight);

	/*if (isIZombieLevel)
	{
		Image* aFilteredImage = FilterEffectGetImage(aImage, FilterEffect::FILTER_EFFECT_WHITE);

		Graphics gFilter(*g);
		gFilter.SetColorizeImages(true);
		gFilter.mTransX = g->mTransX + 4;
		gFilter.mTransY = g->mTransY + 4;
		gFilter.SetColor(Color(122, 86, 58));
		TodDrawImageScaledF(&gFilter, aFilteredImage, thePosX + (aOffsetX * g->mScaleX), thePosY + (aOffsetY * g->mScaleY), g->mScaleX, g->mScaleY);

		gFilter.mTransX = g->mTransX + 2;
		gFilter.mTransY = g->mTransY + 2;
		gFilter.SetColor(Color(171, 135, 107));
		TodDrawImageScaledF(&gFilter, aFilteredImage, thePosX + (aOffsetX * g->mScaleX), thePosY + (aOffsetY * g->mScaleY), g->mScaleX, g->mScaleY);

		gFilter.mTransX = g->mTransX - 2;
		gFilter.mTransY = g->mTransY - 2;
		gFilter.SetColor(Color(171, 135, 107));
		TodDrawImageScaledF(&gFilter, aFilteredImage, thePosX + (aOffsetX * g->mScaleX), thePosY + (aOffsetY * g->mScaleY), g->mScaleX, g->mScaleY);

		gFilter.mTransX = g->mTransX;
		gFilter.mTransY = g->mTransY;
		gFilter.SetColor(Color(255, 201, 160));
		TodDrawImageScaledF(&gFilter, aImage, thePosX + (aOffsetX * g->mScaleX), thePosY + (aOffsetY * g->mScaleY), g->mScaleX, g->mScaleY);
	}
	else*/
	{
		TodDrawImageScaledF(g, aImage, thePosX + (aOffsetX * g->mScaleX), thePosY + (aOffsetY * g->mScaleY), g->mScaleX, g->mScaleY);
	}
}

//0x470110
void ReanimatorCache::DrawCachedMower(Graphics* g, float thePosX, float thePosY, LawnMowerType theMowerType, DrawFilterVariation theFilterVariation)
{
	TOD_ASSERT(theMowerType >= 0 && theMowerType < LawnMowerType::NUM_MOWER_TYPES);
	
	if (mLawnMowers[(int)theMowerType] == nullptr)
		mLawnMowers[(int)theMowerType] = MakeCachedMowerFrame(theMowerType);
	TodDrawImageScaledF(g, mLawnMowers[(int)theMowerType], thePosX - 20.0f, thePosY, g->mScaleX, g->mScaleY);
}

//0x470170
void ReanimatorCache::DrawCachedZombie(Graphics* g, float thePosX, float thePosY, ZombieType theZombieType, DrawFilterVariation theFilterVariation)
{
	TOD_ASSERT(theZombieType >= 0 && theZombieType < ZombieType::NUM_CACHED_ZOMBIE_TYPES);
	
	if (mZombieImages[(int)theZombieType] == nullptr)
		mZombieImages[(int)theZombieType] = MakeCachedZombieFrame(theZombieType);
	TodDrawImageScaledF(g, mZombieImages[(int)theZombieType], thePosX, thePosY, g->mScaleX, g->mScaleY);
}
