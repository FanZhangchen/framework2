[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 100
  ny = 100
[]

[Variables]
  [rhog]
    initial_condition = 0.
  []
  [rhot]
    initial_condition = 1.0
  []
[]

[Kernels]
  [gnd_time_derivative]
    type = ADGNDTimeDerivative
    variable = rhog
  []
  [gnd_transport]
    type = ADGNDTrans
    variable = rhog
    rhot = rhot
    backstress = 1.0
  []
  [total_time_derivative]
    type = ADTotalTimeDerivative
    variable = rhot
  []
  [total_transport]
    type = ADTotalTrans
    variable = rhot
    rhog = rhog
    backstress = 1.0
  []
  [total_source]
    type = ADTotalSource
    variable = rhot
    rhog = rhog
    backstress = 1.0
    source = 0.0
  []
  [total_sink]
    type = ADTotalSink
    variable = rhot
    rhog = rhog
    backstress = 1.0
    sink = 1.0
  []
[]

[BCs]
[]

[Executioner]
  type = Transient
  end_time = 1.0
  dt = 0.005
  solve_type = NEWTON
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[VectorPostprocessors]
  [rhog]
    type = LineValueSampler
    variable = rhog
    start_point = '0 0.5 0'
    end_point = '1 0.5 0'
    num_points = 21
    sort_by = x
  []
  [rhot]
    type = LineValueSampler
    variable = rhot
    start_point = '0 0.5 0'
    end_point = '1 0.5 0'
    num_points = 21
    sort_by = x
  []
[]

[Outputs]
  exodus = true
  [csv]
    type = CSV
    file_base = rho_distr_c1_sink
    execute_on = final
  []
[]