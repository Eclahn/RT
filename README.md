# rtv1

git clone --recurse-submodules 'path-to-repo'

# Algorithme

	[1-(event)]rt_init_projection
		[0-1]free
		[0-1]malloc
		[0-1]rt_vector_cam
			[1]tanf
			[pixel]rt_vector_normalize
				[3]powf
				[1]sqrtf
	[1-(event)]rt_init_origin
		[0-1]free
		[0-1]malloc
		[objet]rt_origin_object
	[1-(event)]rt_init_buffer
		[0-1]free
		[0-1]malloc
		[2 * objet * pixel]rt_matrix_apply
	[pixel]
		[objet]
			rt_collider_* en détail :
				- rt_collider_cone
					[6]powf
					[1]rt_collider_delta
						[1]powf
						[0-1]sqrtf
					[1]rt_apply_limits
						[0-2]rt_vector_impact
				- rt_collider_cylinder
					[5]powf
					[1]rt_collider_delta
						[1]powf
						[0-1]sqrtf
					[1]rt_apply_limits
						[0-2]rt_vector_impact
				- rt_collider_sphere
					[7]powf
					[1]rt_collider_delta
						[1]powf
						[0-1]sqrtf
					[1]rt_apply_limits
						[0-2]rt_vector_impact
				- rt_collider_plane
					[1]rt_apply_limits
				- rt_collider_disk
					[3]powf
					[1]rt_vector_impact
					[1]rt_apply_limits
						[0-2]rt_vector_impact
			rt_collider_* en bref :
				[0-8]powf
				[0-1]sqrtf
				[1]rt_apply_limits
				[0-3]rt_vector_impact
				[0-1]rt_collider_delta
		[1]rt_impact_to_visible
		[objet - 1]rt_first_noticeable
			[1]rt_impact_to_visible
		[impact]
			[1]rt_light_ambient
			[2]rt_vector_impact
			[1]rt_collider_normal
				[0-1]sqrtf
				[0-2]powf
				[0-1]cosf
				[1]rt_vector_normalize
					[3]powf
					[1]sqrtf
				[0-1]rt_vector_impact
				[0-1]rt_vector_angle
			[1]rt_matrix_apply
			[1]rt_impact_to_light
				[1]rt_vector_length
					[1]sqrtf
				[1]rt_vector_normalize
					[3]powf
					[1]sqrtf
				[objet]
					[1]rt_origin_object
					[2]rt_matrix_apply
					[1]rt_collider_* en bref :
						[0-8]powf
						[0-1]sqrtf
						[1]rt_apply_limits
						[0-3]rt_vector_impact
						[0-1]rt_collider_delta
					[1]rt_impact_to_visible
			[0-1]rt_vector_normalize
				[3]powf
				[1]sqrtf
			[0-1]rt_light_reflection
				[1-2]rt_vector_angle
					[1]acosf
				[0-1]rt_diffuse_reflection
					[1]cosf
				[0-1]rt_specular_reflection
					[1]powf
					[1]cosf
