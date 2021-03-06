/*
 * All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
 * its licensors.
 *
 * For complete copyright and license terms please see the LICENSE at the root of this
 * distribution (the "License"). All use of this software is governed by the License,
 * or, if provided, by the license below or the license accompanying this file. Do not
 * remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *
 */
#pragma once

#include <AzFramework/Physics/WorldBodyBus.h>
#include <PhysX/ColliderComponentBus.h>

namespace Blast
{
    AZ_PUSH_DISABLE_WARNING(4996, "-Wdeprecated-declarations")
    class ShapesProvider
        : public PhysX::ColliderComponentRequestBus::Handler
        , public PhysX::BodyConfigurationComponentBus::Handler
    {
    public:
        ShapesProvider(AZ::EntityId entityId, Physics::RigidBodyConfiguration configuration);
        ~ShapesProvider();

        void AddShape(AZStd::shared_ptr<Physics::Shape> shape);

        // This class is not supposed to provide shape configurations, only shapes themselves.
        Physics::ShapeConfigurationList GetShapeConfigurations() override;

        AZStd::vector<AZStd::shared_ptr<Physics::Shape>> GetShapes() override;

        Physics::RigidBodyConfiguration GetRigidBodyConfiguration() override;

        Physics::WorldBodyConfiguration GetWorldBodyConfiguration() override;

    private:
        AZStd::vector<AZStd::shared_ptr<Physics::Shape>> m_shapes;
        AZ::EntityId m_entityId;
        Physics::RigidBodyConfiguration m_configuration;
    };
    AZ_POP_DISABLE_WARNING
} // namespace Blast
