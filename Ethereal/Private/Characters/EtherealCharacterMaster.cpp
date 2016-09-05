// © 2014 - 2016 Soverance Studios
// http://www.soverance.com

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Ethereal.h"
#include "EtherealCharacterMaster.h"


// Sets default values
AEtherealCharacterMaster::AEtherealCharacterMaster(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
		
	// Get Assets, References Obtained Via Right Click in Editor
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshObject(TEXT("StaticMesh'/Game/Shapes/SM_TargetingReticle.SM_TargetingReticle'"));
	
	SM_TargetingReticle = StaticMeshObject.Object;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore); // sets capsule to ignore camera collision

	// Set Default Objects
	TargetingReticle = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Targeting Reticle"));
	TargetingReticle->StaticMesh = SM_TargetingReticle;
	SetupSMComponentsWithCollision(TargetingReticle);
	TargetingReticle->SetupAttachment(GetMesh());

	Targetable = true;  // Set targeting to true
}

// Called when the game starts or when spawned
void AEtherealCharacterMaster::BeginPlay()
{
	Super::BeginPlay();

	// iterate through the world for all Ethereal Audio Managers
	for (TActorIterator<AEtherealAudioManager> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AudioManager = *ActorItr; // get the instance of the Audio Manager
	}
}

// Called every frame
void AEtherealCharacterMaster::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

// Called to bind functionality to input
void AEtherealCharacterMaster::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}

// Activate the Targeting Reticle when Locked On (only used by the player)
void AEtherealCharacterMaster::ToggleReticle(bool Visible)
{
	if (Visible)
	{
		TargetingReticle->SetVisibility(true);
		AudioManager->Play_Target_Notify();
	}
	else
	{
		TargetingReticle->SetVisibility(false);
	}
}

