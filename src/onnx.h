#ifndef __ONNX_H__
#define __ONNX_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <dump.h>
#include <hmap.h>
#include <onnx.proto3.pb-c.h>

#define LIBONNX_VERSION			"1.0.0"

enum onnx_tensor_type_t {
	ONNX_TENSOR_TYPE_UNDEFINED	= 0,
	ONNX_TENSOR_TYPE_BOOL		= 9,
	ONNX_TENSOR_TYPE_INT8		= 3,
	ONNX_TENSOR_TYPE_INT16		= 5,
	ONNX_TENSOR_TYPE_INT32		= 6,
	ONNX_TENSOR_TYPE_INT64		= 7,
	ONNX_TENSOR_TYPE_UINT8		= 2,
	ONNX_TENSOR_TYPE_UINT16		= 4,
	ONNX_TENSOR_TYPE_UINT32		= 12,
	ONNX_TENSOR_TYPE_UINT64		= 13,
	ONNX_TENSOR_TYPE_BFLOAT16	= 16,
	ONNX_TENSOR_TYPE_FLOAT16	= 10,
	ONNX_TENSOR_TYPE_FLOAT32	= 1,
	ONNX_TENSOR_TYPE_FLOAT64	= 11,
	ONNX_TENSOR_TYPE_COMPLEX64	= 14,
	ONNX_TENSOR_TYPE_COMPLEX128	= 15,
	ONNX_TENSOR_TYPE_STRING		= 8,
};

struct onnx_tensor_t;
struct onnx_node_t;
struct onnx_context_t;
struct resolver_t;

struct onnx_tensor_t {
	char * name;
	enum onnx_tensor_type_t type;
	int64_t * dims, * datas;
	int ndim, ndata;
};

struct onnx_node_t {
	struct onnx_context_t * ctx;
	Onnx__NodeProto * proto;
	struct onnx_tensor_t ** inputs;
	int ninput;
	struct onnx_tensor_t ** outputs;
	int noutput;

	void (*init)(struct onnx_node_t * n);
	void (*exit)(struct onnx_node_t * n);
	void (*op)(struct onnx_node_t * n);
	void * priv;
};

struct onnx_context_t {
	Onnx__ModelProto * model;
	struct onnx_node_t * nodes;
	int nlen;
	struct hmap_t * map;
};

struct resolver_t {
	const char * name;

	void (*op_Abs)(struct onnx_node_t * n);
	void (*op_Acos)(struct onnx_node_t * n);
	void (*op_Acosh)(struct onnx_node_t * n);
	void (*op_Add)(struct onnx_node_t * n);
	void (*op_And)(struct onnx_node_t * n);
	void (*op_ArgMax)(struct onnx_node_t * n);
	void (*op_ArgMin)(struct onnx_node_t * n);
	void (*op_Asin)(struct onnx_node_t * n);
	void (*op_Asinh)(struct onnx_node_t * n);
	void (*op_Atan)(struct onnx_node_t * n);
	void (*op_Atanh)(struct onnx_node_t * n);
	void (*op_AveragePool)(struct onnx_node_t * n);
	void (*op_BatchNormalization)(struct onnx_node_t * n);
	void (*op_BitShift)(struct onnx_node_t * n);
	void (*op_Cast)(struct onnx_node_t * n);
	void (*op_Ceil)(struct onnx_node_t * n);
	void (*op_Clip)(struct onnx_node_t * n);
	void (*op_Compress)(struct onnx_node_t * n);
	void (*op_Concat)(struct onnx_node_t * n);
	void (*op_ConcatFromSequence)(struct onnx_node_t * n);
	void (*op_Constant)(struct onnx_node_t * n);
	void (*op_ConstantOfShape)(struct onnx_node_t * n);
	void (*op_Conv)(struct onnx_node_t * n);
	void (*op_ConvInteger)(struct onnx_node_t * n);
	void (*op_ConvTranspose)(struct onnx_node_t * n);
	void (*op_Cos)(struct onnx_node_t * n);
	void (*op_Cosh)(struct onnx_node_t * n);
	void (*op_CumSum)(struct onnx_node_t * n);
	void (*op_DepthToSpace)(struct onnx_node_t * n);
	void (*op_DequantizeLinear)(struct onnx_node_t * n);
	void (*op_Det)(struct onnx_node_t * n);
	void (*op_Div)(struct onnx_node_t * n);
	void (*op_Dropout)(struct onnx_node_t * n);
	void (*op_Einsum)(struct onnx_node_t * n);
	void (*op_Elu)(struct onnx_node_t * n);
	void (*op_Equal)(struct onnx_node_t * n);
	void (*op_Erf)(struct onnx_node_t * n);
	void (*op_Exp)(struct onnx_node_t * n);
	void (*op_Expand)(struct onnx_node_t * n);
	void (*op_EyeLike)(struct onnx_node_t * n);
	void (*op_Flatten)(struct onnx_node_t * n);
	void (*op_Floor)(struct onnx_node_t * n);
	void (*op_GRU)(struct onnx_node_t * n);
	void (*op_Gather)(struct onnx_node_t * n);
	void (*op_GatherElements)(struct onnx_node_t * n);
	void (*op_GatherND)(struct onnx_node_t * n);
	void (*op_Gemm)(struct onnx_node_t * n);
	void (*op_GlobalAveragePool)(struct onnx_node_t * n);
	void (*op_GlobalLpPool)(struct onnx_node_t * n);
	void (*op_GlobalMaxPool)(struct onnx_node_t * n);
	void (*op_Greater)(struct onnx_node_t * n);
	void (*op_HardSigmoid)(struct onnx_node_t * n);
	void (*op_Hardmax)(struct onnx_node_t * n);
	void (*op_Identity)(struct onnx_node_t * n);
	void (*op_If)(struct onnx_node_t * n);
	void (*op_InstanceNormalization)(struct onnx_node_t * n);
	void (*op_IsInf)(struct onnx_node_t * n);
	void (*op_IsNaN)(struct onnx_node_t * n);
	void (*op_LRN)(struct onnx_node_t * n);
	void (*op_LSTM)(struct onnx_node_t * n);
	void (*op_LeakyRelu)(struct onnx_node_t * n);
	void (*op_Less)(struct onnx_node_t * n);
	void (*op_Log)(struct onnx_node_t * n);
	void (*op_Loop)(struct onnx_node_t * n);
	void (*op_LpNormalization)(struct onnx_node_t * n);
	void (*op_LpPool)(struct onnx_node_t * n);
	void (*op_MatMul)(struct onnx_node_t * n);
	void (*op_MatMulInteger)(struct onnx_node_t * n);
	void (*op_Max)(struct onnx_node_t * n);
	void (*op_MaxPool)(struct onnx_node_t * n);
	void (*op_MaxRoiPool)(struct onnx_node_t * n);
	void (*op_MaxUnpool)(struct onnx_node_t * n);
	void (*op_Mean)(struct onnx_node_t * n);
	void (*op_Min)(struct onnx_node_t * n);
	void (*op_Mod)(struct onnx_node_t * n);
	void (*op_Mul)(struct onnx_node_t * n);
	void (*op_Multinomial)(struct onnx_node_t * n);
	void (*op_Neg)(struct onnx_node_t * n);
	void (*op_NonMaxSuppression)(struct onnx_node_t * n);
	void (*op_NonZero)(struct onnx_node_t * n);
	void (*op_Not)(struct onnx_node_t * n);
	void (*op_OneHot)(struct onnx_node_t * n);
	void (*op_Or)(struct onnx_node_t * n);
	void (*op_PRelu)(struct onnx_node_t * n);
	void (*op_Pad)(struct onnx_node_t * n);
	void (*op_Pow)(struct onnx_node_t * n);
	void (*op_QLinearConv)(struct onnx_node_t * n);
	void (*op_QLinearMatMul)(struct onnx_node_t * n);
	void (*op_QuantizeLinear)(struct onnx_node_t * n);
	void (*op_RNN)(struct onnx_node_t * n);
	void (*op_RandomNormal)(struct onnx_node_t * n);
	void (*op_RandomNormalLike)(struct onnx_node_t * n);
	void (*op_RandomUniform)(struct onnx_node_t * n);
	void (*op_RandomUniformLike)(struct onnx_node_t * n);
	void (*op_Reciprocal)(struct onnx_node_t * n);
	void (*op_ReduceL1)(struct onnx_node_t * n);
	void (*op_ReduceL2)(struct onnx_node_t * n);
	void (*op_ReduceLogSum)(struct onnx_node_t * n);
	void (*op_ReduceLogSumExp)(struct onnx_node_t * n);
	void (*op_ReduceMax)(struct onnx_node_t * n);
	void (*op_ReduceMean)(struct onnx_node_t * n);
	void (*op_ReduceMin)(struct onnx_node_t * n);
	void (*op_ReduceProd)(struct onnx_node_t * n);
	void (*op_ReduceSum)(struct onnx_node_t * n);
	void (*op_ReduceSumSquare)(struct onnx_node_t * n);
	void (*op_Relu)(struct onnx_node_t * n);
	void (*op_Reshape)(struct onnx_node_t * n);
	void (*op_Resize)(struct onnx_node_t * n);
	void (*op_ReverseSequence)(struct onnx_node_t * n);
	void (*op_RoiAlign)(struct onnx_node_t * n);
	void (*op_Round)(struct onnx_node_t * n);
	void (*op_Scan)(struct onnx_node_t * n);
	void (*op_ScatterElements)(struct onnx_node_t * n);
	void (*op_ScatterND)(struct onnx_node_t * n);
	void (*op_Selu)(struct onnx_node_t * n);
	void (*op_SequenceAt)(struct onnx_node_t * n);
	void (*op_SequenceConstruct)(struct onnx_node_t * n);
	void (*op_SequenceEmpty)(struct onnx_node_t * n);
	void (*op_SequenceErase)(struct onnx_node_t * n);
	void (*op_SequenceInsert)(struct onnx_node_t * n);
	void (*op_SequenceLength)(struct onnx_node_t * n);
	void (*op_Shape)(struct onnx_node_t * n);
	void (*op_Shrink)(struct onnx_node_t * n);
	void (*op_Sigmoid)(struct onnx_node_t * n);
	void (*op_Sign)(struct onnx_node_t * n);
	void (*op_Sin)(struct onnx_node_t * n);
	void (*op_Sinh)(struct onnx_node_t * n);
	void (*op_Size)(struct onnx_node_t * n);
	void (*op_Slice)(struct onnx_node_t * n);
	void (*op_Softplus)(struct onnx_node_t * n);
	void (*op_Softsign)(struct onnx_node_t * n);
	void (*op_SpaceToDepth)(struct onnx_node_t * n);
	void (*op_Split)(struct onnx_node_t * n);
	void (*op_SplitToSequence)(struct onnx_node_t * n);
	void (*op_Sqrt)(struct onnx_node_t * n);
	void (*op_Squeeze)(struct onnx_node_t * n);
	void (*op_StringNormalizer)(struct onnx_node_t * n);
	void (*op_Sub)(struct onnx_node_t * n);
	void (*op_Sum)(struct onnx_node_t * n);
	void (*op_Tan)(struct onnx_node_t * n);
	void (*op_Tanh)(struct onnx_node_t * n);
	void (*op_TfIdfVectorizer)(struct onnx_node_t * n);
	void (*op_ThresholdedRelu)(struct onnx_node_t * n);
	void (*op_Tile)(struct onnx_node_t * n);
	void (*op_TopK)(struct onnx_node_t * n);
	void (*op_Transpose)(struct onnx_node_t * n);
	void (*op_Unique)(struct onnx_node_t * n);
	void (*op_Unsqueeze)(struct onnx_node_t * n);
	void (*op_Where)(struct onnx_node_t * n);
	void (*op_Xor)(struct onnx_node_t * n);

	void (*op_Celu)(struct onnx_node_t * n);
	void (*op_DynamicQuantizeLinear)(struct onnx_node_t * n);
	void (*op_GreaterOrEqual)(struct onnx_node_t * n);
	void (*op_LessOrEqual)(struct onnx_node_t * n);
	void (*op_LogSoftmax)(struct onnx_node_t * n);
	void (*op_MeanVarianceNormalization)(struct onnx_node_t * n);
	void (*op_NegativeLogLikelihoodLoss)(struct onnx_node_t * n);
	void (*op_Range)(struct onnx_node_t * n);
	void (*op_Softmax)(struct onnx_node_t * n);
	void (*op_SoftmaxCrossEntropyLoss)(struct onnx_node_t * n);
};

void default_resolver_op_Abs(struct onnx_node_t * n);
void default_resolver_op_Acos(struct onnx_node_t * n);
void default_resolver_op_Acosh(struct onnx_node_t * n);
void default_resolver_op_Add(struct onnx_node_t * n);
void default_resolver_op_And(struct onnx_node_t * n);
void default_resolver_op_ArgMax(struct onnx_node_t * n);
void default_resolver_op_ArgMin(struct onnx_node_t * n);
void default_resolver_op_Asin(struct onnx_node_t * n);
void default_resolver_op_Asinh(struct onnx_node_t * n);
void default_resolver_op_Atan(struct onnx_node_t * n);
void default_resolver_op_Atanh(struct onnx_node_t * n);
void default_resolver_op_AveragePool(struct onnx_node_t * n);
void default_resolver_op_BatchNormalization(struct onnx_node_t * n);
void default_resolver_op_BitShift(struct onnx_node_t * n);
void default_resolver_op_Cast(struct onnx_node_t * n);
void default_resolver_op_Ceil(struct onnx_node_t * n);
void default_resolver_op_Clip(struct onnx_node_t * n);
void default_resolver_op_Compress(struct onnx_node_t * n);
void default_resolver_op_Concat(struct onnx_node_t * n);
void default_resolver_op_ConcatFromSequence(struct onnx_node_t * n);
void default_resolver_op_Constant(struct onnx_node_t * n);
void default_resolver_op_ConstantOfShape(struct onnx_node_t * n);
void default_resolver_op_Conv(struct onnx_node_t * n);
void default_resolver_op_ConvInteger(struct onnx_node_t * n);
void default_resolver_op_ConvTranspose(struct onnx_node_t * n);
void default_resolver_op_Cos(struct onnx_node_t * n);
void default_resolver_op_Cosh(struct onnx_node_t * n);
void default_resolver_op_CumSum(struct onnx_node_t * n);
void default_resolver_op_DepthToSpace(struct onnx_node_t * n);
void default_resolver_op_DequantizeLinear(struct onnx_node_t * n);
void default_resolver_op_Det(struct onnx_node_t * n);
void default_resolver_op_Div(struct onnx_node_t * n);
void default_resolver_op_Dropout(struct onnx_node_t * n);
void default_resolver_op_Einsum(struct onnx_node_t * n);
void default_resolver_op_Elu(struct onnx_node_t * n);
void default_resolver_op_Equal(struct onnx_node_t * n);
void default_resolver_op_Erf(struct onnx_node_t * n);
void default_resolver_op_Exp(struct onnx_node_t * n);
void default_resolver_op_Expand(struct onnx_node_t * n);
void default_resolver_op_EyeLike(struct onnx_node_t * n);
void default_resolver_op_Flatten(struct onnx_node_t * n);
void default_resolver_op_Floor(struct onnx_node_t * n);
void default_resolver_op_GRU(struct onnx_node_t * n);
void default_resolver_op_Gather(struct onnx_node_t * n);
void default_resolver_op_GatherElements(struct onnx_node_t * n);
void default_resolver_op_GatherND(struct onnx_node_t * n);
void default_resolver_op_Gemm(struct onnx_node_t * n);
void default_resolver_op_GlobalAveragePool(struct onnx_node_t * n);
void default_resolver_op_GlobalLpPool(struct onnx_node_t * n);
void default_resolver_op_GlobalMaxPool(struct onnx_node_t * n);
void default_resolver_op_Greater(struct onnx_node_t * n);
void default_resolver_op_HardSigmoid(struct onnx_node_t * n);
void default_resolver_op_Hardmax(struct onnx_node_t * n);
void default_resolver_op_Identity(struct onnx_node_t * n);
void default_resolver_op_If(struct onnx_node_t * n);
void default_resolver_op_InstanceNormalization(struct onnx_node_t * n);
void default_resolver_op_IsInf(struct onnx_node_t * n);
void default_resolver_op_IsNaN(struct onnx_node_t * n);
void default_resolver_op_LRN(struct onnx_node_t * n);
void default_resolver_op_LSTM(struct onnx_node_t * n);
void default_resolver_op_LeakyRelu(struct onnx_node_t * n);
void default_resolver_op_Less(struct onnx_node_t * n);
void default_resolver_op_Log(struct onnx_node_t * n);
void default_resolver_op_Loop(struct onnx_node_t * n);
void default_resolver_op_LpNormalization(struct onnx_node_t * n);
void default_resolver_op_LpPool(struct onnx_node_t * n);
void default_resolver_op_MatMul(struct onnx_node_t * n);
void default_resolver_op_MatMulInteger(struct onnx_node_t * n);
void default_resolver_op_Max(struct onnx_node_t * n);
void default_resolver_op_MaxPool(struct onnx_node_t * n);
void default_resolver_op_MaxRoiPool(struct onnx_node_t * n);
void default_resolver_op_MaxUnpool(struct onnx_node_t * n);
void default_resolver_op_Mean(struct onnx_node_t * n);
void default_resolver_op_Min(struct onnx_node_t * n);
void default_resolver_op_Mod(struct onnx_node_t * n);
void default_resolver_op_Mul(struct onnx_node_t * n);
void default_resolver_op_Multinomial(struct onnx_node_t * n);
void default_resolver_op_Neg(struct onnx_node_t * n);
void default_resolver_op_NonMaxSuppression(struct onnx_node_t * n);
void default_resolver_op_NonZero(struct onnx_node_t * n);
void default_resolver_op_Not(struct onnx_node_t * n);
void default_resolver_op_OneHot(struct onnx_node_t * n);
void default_resolver_op_Or(struct onnx_node_t * n);
void default_resolver_op_PRelu(struct onnx_node_t * n);
void default_resolver_op_Pad(struct onnx_node_t * n);
void default_resolver_op_Pow(struct onnx_node_t * n);
void default_resolver_op_QLinearConv(struct onnx_node_t * n);
void default_resolver_op_QLinearMatMul(struct onnx_node_t * n);
void default_resolver_op_QuantizeLinear(struct onnx_node_t * n);
void default_resolver_op_RNN(struct onnx_node_t * n);
void default_resolver_op_RandomNormal(struct onnx_node_t * n);
void default_resolver_op_RandomNormalLike(struct onnx_node_t * n);
void default_resolver_op_RandomUniform(struct onnx_node_t * n);
void default_resolver_op_RandomUniformLike(struct onnx_node_t * n);
void default_resolver_op_Reciprocal(struct onnx_node_t * n);
void default_resolver_op_ReduceL1(struct onnx_node_t * n);
void default_resolver_op_ReduceL2(struct onnx_node_t * n);
void default_resolver_op_ReduceLogSum(struct onnx_node_t * n);
void default_resolver_op_ReduceLogSumExp(struct onnx_node_t * n);
void default_resolver_op_ReduceMax(struct onnx_node_t * n);
void default_resolver_op_ReduceMean(struct onnx_node_t * n);
void default_resolver_op_ReduceMin(struct onnx_node_t * n);
void default_resolver_op_ReduceProd(struct onnx_node_t * n);
void default_resolver_op_ReduceSum(struct onnx_node_t * n);
void default_resolver_op_ReduceSumSquare(struct onnx_node_t * n);
void default_resolver_op_Relu(struct onnx_node_t * n);
void default_resolver_op_Reshape(struct onnx_node_t * n);
void default_resolver_op_Resize(struct onnx_node_t * n);
void default_resolver_op_ReverseSequence(struct onnx_node_t * n);
void default_resolver_op_RoiAlign(struct onnx_node_t * n);
void default_resolver_op_Round(struct onnx_node_t * n);
void default_resolver_op_Scan(struct onnx_node_t * n);
void default_resolver_op_ScatterElements(struct onnx_node_t * n);
void default_resolver_op_ScatterND(struct onnx_node_t * n);
void default_resolver_op_Selu(struct onnx_node_t * n);
void default_resolver_op_SequenceAt(struct onnx_node_t * n);
void default_resolver_op_SequenceConstruct(struct onnx_node_t * n);
void default_resolver_op_SequenceEmpty(struct onnx_node_t * n);
void default_resolver_op_SequenceErase(struct onnx_node_t * n);
void default_resolver_op_SequenceInsert(struct onnx_node_t * n);
void default_resolver_op_SequenceLength(struct onnx_node_t * n);
void default_resolver_op_Shape(struct onnx_node_t * n);
void default_resolver_op_Shrink(struct onnx_node_t * n);
void default_resolver_op_Sigmoid(struct onnx_node_t * n);
void default_resolver_op_Sign(struct onnx_node_t * n);
void default_resolver_op_Sin(struct onnx_node_t * n);
void default_resolver_op_Sinh(struct onnx_node_t * n);
void default_resolver_op_Size(struct onnx_node_t * n);
void default_resolver_op_Slice(struct onnx_node_t * n);
void default_resolver_op_Softplus(struct onnx_node_t * n);
void default_resolver_op_Softsign(struct onnx_node_t * n);
void default_resolver_op_SpaceToDepth(struct onnx_node_t * n);
void default_resolver_op_Split(struct onnx_node_t * n);
void default_resolver_op_SplitToSequence(struct onnx_node_t * n);
void default_resolver_op_Sqrt(struct onnx_node_t * n);
void default_resolver_op_Squeeze(struct onnx_node_t * n);
void default_resolver_op_StringNormalizer(struct onnx_node_t * n);
void default_resolver_op_Sub(struct onnx_node_t * n);
void default_resolver_op_Sum(struct onnx_node_t * n);
void default_resolver_op_Tan(struct onnx_node_t * n);
void default_resolver_op_Tanh(struct onnx_node_t * n);
void default_resolver_op_TfIdfVectorizer(struct onnx_node_t * n);
void default_resolver_op_ThresholdedRelu(struct onnx_node_t * n);
void default_resolver_op_Tile(struct onnx_node_t * n);
void default_resolver_op_TopK(struct onnx_node_t * n);
void default_resolver_op_Transpose(struct onnx_node_t * n);
void default_resolver_op_Unique(struct onnx_node_t * n);
void default_resolver_op_Unsqueeze(struct onnx_node_t * n);
void default_resolver_op_Where(struct onnx_node_t * n);
void default_resolver_op_Xor(struct onnx_node_t * n);

void default_resolver_op_Celu(struct onnx_node_t * n);
void default_resolver_op_DynamicQuantizeLinear(struct onnx_node_t * n);
void default_resolver_op_GreaterOrEqual(struct onnx_node_t * n);
void default_resolver_op_LessOrEqual(struct onnx_node_t * n);
void default_resolver_op_LogSoftmax(struct onnx_node_t * n);
void default_resolver_op_MeanVarianceNormalization(struct onnx_node_t * n);
void default_resolver_op_NegativeLogLikelihoodLoss(struct onnx_node_t * n);
void default_resolver_op_Range(struct onnx_node_t * n);
void default_resolver_op_Softmax(struct onnx_node_t * n);
void default_resolver_op_SoftmaxCrossEntropyLoss(struct onnx_node_t * n);

struct onnx_context_t * onnx_context_alloc(const void * buf, size_t len, struct resolver_t * r);
struct onnx_context_t * onnx_context_alloc_from_file(const char * filename, struct resolver_t * r);
void onnx_context_free(struct onnx_context_t * ctx);

int onnx_tensor_type_size(enum onnx_tensor_type_t type);
struct onnx_tensor_t * onnx_search_tensor(struct onnx_context_t * ctx, const char * name);
struct onnx_tensor_t * onnx_tensor_alloc(const char * name, enum onnx_tensor_type_t type, int64_t * dims, int ndim);
struct onnx_tensor_t * onnx_tensor_alloc_from_file(const char * filename);
void onnx_tensor_free(struct onnx_tensor_t * t);
void onnx_tensor_reinit(struct onnx_tensor_t * t, enum onnx_tensor_type_t type, int64_t * dims, int ndim);
void onnx_tensor_apply(struct onnx_tensor_t * t, void * buf, int len);

float onnx_attribute_read_float(struct onnx_node_t * n, const char * name, float def);
int64_t onnx_attribute_read_int(struct onnx_node_t * n, const char * name, int64_t def);
char * onnx_attribute_read_string(struct onnx_node_t * n, const char * name, char * def);
Onnx__TensorProto * onnx_attribute_read_tensor(struct onnx_node_t * n, const char * name, Onnx__TensorProto * def);
Onnx__GraphProto * onnx_attribute_read_graph(struct onnx_node_t * n, const char * name, Onnx__GraphProto * def);
Onnx__SparseTensorProto * onnx_attribute_read_sparse_tensor(struct onnx_node_t * n, const char * name, Onnx__SparseTensorProto * def);

void onnx_run(struct onnx_context_t * ctx);

#ifdef __cplusplus
}
#endif

#endif /* __ONNX_H__ */
